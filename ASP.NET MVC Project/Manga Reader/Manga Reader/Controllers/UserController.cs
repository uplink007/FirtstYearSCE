using Manga_Reader.Classes;
using Manga_Reader.Dal;
using Manga_Reader.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Data.Entity;
using System.Web.Security;
using System.Web.Services;
using System.Web.Configuration;
using System.Web.UI.WebControls;
using System.Web.Script.Serialization;

namespace Manga_Reader.Controllers
{
    public class UserController : Controller
    {
        // GET: User
        [AllowAnonymous]
        public ActionResult Register()
        {

            if(User.Identity.IsAuthenticated)
            {
                return RedirectToAction("Home", "Home");
            }
            return View();
        }
        [AllowAnonymous]
        public ActionResult RegisterSubmit(User usr)
        {
            if (User.Identity.IsAuthenticated)
            {
                return RedirectToAction("Home", "Home");
            }
            if (ModelState.IsValid && Session["userValid"].ToString() == "0")
            {
                ReaderDal dal = new ReaderDal();
                Encryp enc = new Encryp();

                string hashPassword = enc.CreateHash(usr.Password);
                usr.Password = hashPassword;
                dal.Users.Add(usr);

                dal.SaveChanges();


                string authId = Guid.NewGuid().ToString();

                Session["AuthID"] = authId;
                Session["Permission"] = usr.Permission;
                FormsAuthentication.SetAuthCookie(usr.uid.ToString(), false);
                return RedirectToAction("Home", "Home");
            }
            else
                return View("Register", usr);
        }
        [AllowAnonymous]
        public ActionResult LoginSubmit(User user) {
            if (User.Identity.IsAuthenticated)
            {
                return RedirectToAction("Home", "Home");
            }
            ReaderDal dal = new ReaderDal();
            Encryp enc = new Encryp();
            if (!ModelState.IsValid)
            {
                ViewBag.loginMessage = "Invalid Username/Password.";
                return View("Login", user);
            }
            List<User> userToCheck = GetUsersByUsername(user.UserName);

            if (userToCheck != null && userToCheck.Count>0)
            {
                if (enc.ValidatePassword(user.Password, userToCheck[0].Password))
                {
                    ViewBag.loginMessage = "Login Succesfull.";
                    string authId = Guid.NewGuid().ToString();

                    Session["AuthID"] = authId;
                    Session["Permission"] = userToCheck[0].Permission;
                    FormsAuthentication.SetAuthCookie(userToCheck[0].uid.ToString(), false);
                    return RedirectToAction("Home", "Home");

                }
                else
                {
                    ViewBag.loginMessage = "Incorrect Username/Password.";
                }
            }
            return View("Login", user);

        }
        [AllowAnonymous]
        public ActionResult Login(User user)
        {
            if (User.Identity.IsAuthenticated)
            {
                return RedirectToAction("Home", "Home");
            }
            return View("Login", user);
        }
        [AllowAnonymous]
        public ActionResult CheckUserNameAvailability(string username)
        {
            if (User.Identity.IsAuthenticated)
            {
                return RedirectToAction("Home", "Home");
            }
            using (var context = new ReaderDal())
            {
                var blogs = (from b in context.Users
                             where b.UserName.Equals(username)
                             select b).Count();
                Session["userValid"] = blogs.ToString();
                return Json(new { d = blogs.ToString(),userName=username }, JsonRequestBehavior.AllowGet);
            }
        }

        [Authorize]
        public ActionResult Logout()
        {

            FormsAuthentication.SignOut();
            Session.Abandon();

            // clear authentication cookie
            HttpCookie cookie1 = new HttpCookie(FormsAuthentication.FormsCookieName, "");
            cookie1.Expires = DateTime.Now.AddYears(-1);
            Response.Cookies.Add(cookie1);

            // clear session cookie (not necessary for your current problem but i would recommend you do it anyway)
            SessionStateSection sessionStateSection = (SessionStateSection)WebConfigurationManager.GetSection("system.web/sessionState");
            HttpCookie cookie2 = new HttpCookie(sessionStateSection.CookieName, "");
            cookie2.Expires = DateTime.Now.AddYears(-1);
            Response.Cookies.Add(cookie2);

            FormsAuthentication.RedirectToLoginPage();

            return RedirectToAction("Home", "Home");
        }

        [Authorize]
        public new ActionResult Profile()
        {

            ReaderDal dal = new ReaderDal();
            VMMangaList vm = new VMMangaList();
            int UserID;
            int.TryParse(System.Web.HttpContext.Current.User.Identity.Name, out UserID);
            User usr = dal.Users.Find(UserID);
            vm.usr = usr;

            vm.MangaList = (from x in usr.Bookmarks where x.IsRemoved == false select x).ToList<Manga>();
            return View(vm);
        }
        [Authorize]
        public ActionResult AddBookmark(string mid)
        {
            int MangaID;
            int UserID;
            if (int.TryParse(mid, out MangaID) && int.TryParse(System.Web.HttpContext.Current.User.Identity.Name, out UserID))
            {
                ReaderDal dal = new ReaderDal();
                User usr = dal.Users.Find(UserID);
                if (usr.Permission == Permissions.Guest)
                    return Json(new { success = false, Message = "You are BANNED!" });
                Manga m = dal.Manga.Find(MangaID);
                usr.Bookmarks.Add(m);
                m.Bookmarked.Add(usr);
                dal.SaveChanges();


                return Json(new { success = true, Message = "Bookmarked" });
                }
            else
                return View("Error");
        }




        public static List<User> GetUsersByUsername(string username)
        {
            ReaderDal dal = new ReaderDal();
            List<User> users = (from x in dal.Users
                                      where x.UserName == username
                                      select x).ToList<User>();
            return users;
        }

        public static User GetUserByID(int? uid)
        {
            ReaderDal dal = new ReaderDal();
            if (uid != null)
                return dal.Users.Find(uid);
            else
                return null;
        }

        public static Permissions getPermissionByID(int? uid)
        {
            User usr;
            ReaderDal dal = new ReaderDal();
            if (uid != null)
                usr =  dal.Users.Find(uid);
            else
                usr = null;

            if(usr == null)
            {
                return Permissions.Guest;
            }
            else
            {
                return usr.Permission;
            }
        }
        [Authorize]
        public ActionResult ManageUsers(List<User> userList)
        {
            int uid;
            Permissions perm;
            Int32.TryParse(User.Identity.Name, out uid);
            if (Int32.TryParse(User.Identity.Name, out uid))
                perm = UserController.getPermissionByID(uid);
            else
                perm = Permissions.Guest;

            if (perm == Permissions.Admin)
            {
                return View("UserManagement");
            }
            else return View("PermissionError");
        }

        [Authorize]
        public ActionResult ManageUsersGetUsers()
        {
            int uid;
            Permissions perm;
            Int32.TryParse(User.Identity.Name, out uid);
            if (Int32.TryParse(User.Identity.Name, out uid))
                perm = UserController.getPermissionByID(uid);
            else
                perm = Permissions.Guest;

            if (perm == Permissions.Admin)
            {
                return Json(getUsers(uid), JsonRequestBehavior.AllowGet);
            }
            else return View("PermissionError");
        }
        
        private static List<User> getUsers(int uid) {
            ReaderDal dal = new ReaderDal();
            dal.Configuration.ProxyCreationEnabled = false;
            return (from x in dal.Users where x.uid != uid select x).ToList();
        }
        [Authorize]
        public ActionResult promote(int? uidUser )
        {
            int uid;
            Permissions perm;
            Int32.TryParse(User.Identity.Name, out uid);
            if (Int32.TryParse(User.Identity.Name, out uid))
                perm = UserController.getPermissionByID(uid);
            else
                perm = Permissions.Guest;

            if (perm == Permissions.Admin && uidUser != null)
            {
                ReaderDal dal = new ReaderDal();
                User user = dal.Users.Find(uidUser);
                if (user.Permission < Permissions.Admin)
                {
                    user.Permission = (Permissions)(++(user.Permission));
                    dal.SaveChanges();
                }
                return Json(getUsers(uid), JsonRequestBehavior.AllowGet);
            }
            else return View("PermissionError");
        }

        [Authorize]
        public ActionResult demote(int? uidUser )
        {
            int uid;
            Permissions perm;
            Int32.TryParse(User.Identity.Name, out uid);
            if (Int32.TryParse(User.Identity.Name, out uid))
                perm = UserController.getPermissionByID(uid);
            else
                perm = Permissions.Guest;

            if (perm == Permissions.Admin && uidUser!=null)
            {
                ReaderDal dal = new ReaderDal();
                User user = dal.Users.Find(uidUser);
                if (user.Permission > Permissions.Guest) {
                    user.Permission = (Permissions)(--(user.Permission));
                    dal.SaveChanges();
                }
                return Json(getUsers(uid), JsonRequestBehavior.AllowGet);
            }
            else return View("PermissionError");
        }


    }
}

