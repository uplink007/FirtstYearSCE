using Ionic.Zip;
using Manga_Reader.Dal;
using Manga_Reader.Models;
using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Compression;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Manga_Reader.Controllers
{



    public class ChapterController : Controller
    {
        // GET: Chapter
        [AllowAnonymous]
        public ActionResult ViewChapter(int? ChapterID)
        {

            ReaderDal dal = new ReaderDal();
            Chapter c = dal.Chapters.Find(ChapterID);
            if (c != null)
            {
                return View(c);
            }
            return View("Error");
        }

        [Authorize]
        public ActionResult AddChapter(int? mid)
        {

            int uid;
            Permissions perm;
            Int32.TryParse(User.Identity.Name, out uid);
            if (Int32.TryParse(User.Identity.Name, out uid))
                perm = UserController.getPermissionByID(uid);
            else
                perm = Permissions.Guest;

            if (perm == Permissions.Admin || perm == Permissions.Uploader)
            {
                ReaderDal dal = new ReaderDal();
                Manga m = dal.Manga.Find(mid);
                if (m != null)
                {
                    VMMangaChapter vm = new VMMangaChapter();
                    vm.Chapter = new Chapter();
                    vm.Manga = m;
                    return View(vm);
                }
            }
            return View("PermissionError");
        }

        [Authorize]
        public ActionResult CreateChapter(VMMangaChapter vm,HttpPostedFileBase file,int? mid)
        {

            if (mid == null) return View("Error");

            int uid;
            Permissions perm;
            Int32.TryParse(User.Identity.Name, out uid);
            if (Int32.TryParse(User.Identity.Name, out uid))
                perm = UserController.getPermissionByID(uid);
            else
                perm = Permissions.Guest;

            if (perm != Permissions.Admin && perm != Permissions.Uploader)
            {
                return View("PermissionError");
            }

            ReaderDal dal = new ReaderDal();
            Manga m = dal.Manga.Find(mid);
            vm.Manga = m;
            vm.Manga.Chapters.Add(vm.Chapter);
            dal.SaveChanges();
            if (file.ContentLength > 0)
            {

                var fileName = Path.GetFileName(file.FileName);
                var path = Path.Combine(Server.MapPath("~/Manga_DATA/"), fileName);
                file.SaveAs(path);





                int i = 1;
                using (ZipFile zip2 = ZipFile.Read(path))
                {
                    foreach (ZipEntry e in zip2.ToList<ZipEntry>())
                    {
                        e.FileName = i.ToString() + ".jpg";
                        i++;
                    }
                    zip2.Save();
                }


                using (ZipFile chapter = ZipFile.Read(path))
                {
                    chapter.ExtractAll(Server.MapPath("~/Manga_DATA/") + vm.Manga.mid + "/" + vm.Chapter.cid);
                }
                vm.Chapter.Path = vm.Manga.mid + "/" + vm.Chapter.cid;
                vm.Chapter.PageNum = i; 
                dal.SaveChanges();

                if (System.IO.File.Exists(path))
                {
                    System.IO.File.Delete(path);
                }

            }
            return RedirectToAction("Home", "Home", null);
        }



    }
}