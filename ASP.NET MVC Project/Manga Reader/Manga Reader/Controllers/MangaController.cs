using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using Manga_Reader.Models;
using Manga_Reader.Dal;

namespace Manga_Reader.Controllers
{
    public class MangaController : Controller
    {
        // GET: Manga
        [Authorize]
        public ActionResult AddManga()
        {
            int uid;
            Permissions perm;
            Int32.TryParse(User.Identity.Name, out uid);
            if (Int32.TryParse(User.Identity.Name, out uid))
                perm = UserController.getPermissionByID(uid);
            else
                perm = Permissions.Guest;

            if (perm == Permissions.Admin || perm == Permissions.Uploader)
                return View();
            else return View("PermissionError");
        }

        [HttpPost]
        [Authorize]
        public ActionResult SubmitManga(Manga m)
        {

            if (ModelState.IsValid)
            {
                ReaderDal dal = new ReaderDal();
                dal.Manga.Add(m);
                dal.SaveChanges();
                return RedirectToAction("ViewManga",new
                {
                    MangaID = m.mid
                });
            }
            else
                return View("AddManga");
        }

        [AllowAnonymous]
        public ActionResult MangaList()
        {
            ReaderDal dal = new ReaderDal();
            VMMangaList vm = new VMMangaList();
            vm.MangaList = (from x in dal.Manga where x.IsRemoved == false select x).ToList<Manga>();
            return View(vm);
        }


        [AllowAnonymous]
        public ActionResult ViewManga(int? MangaID)
        {
            ReaderDal dal = new ReaderDal();
            Manga m = dal.Manga.Find(MangaID);
            if(m != null)
                return View(m);
            return View("Error");
        }

        [Authorize]
        public ActionResult RemoveManga(int? mid)
        {
            int uid;
            Permissions perm;
            Int32.TryParse(User.Identity.Name, out uid);
            if (Int32.TryParse(User.Identity.Name, out uid))
                perm = UserController.getPermissionByID(uid);
            else
                perm = Permissions.Guest;

            if (perm == Permissions.Admin && mid != null)
            {
                ReaderDal dal = new ReaderDal();
                Manga m = dal.Manga.Find(mid);
                if (m != null)
                {
                    m.IsRemoved = true;
                    dal.SaveChanges();
                }
                return RedirectToAction("MangaList");
            }
            else return View("PermissionError");
        }




       
    }
}