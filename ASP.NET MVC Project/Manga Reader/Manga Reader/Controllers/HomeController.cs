using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using Manga_Reader.Dal;
using Manga_Reader.Models;

namespace Manga_Reader.Controllers
{
    [AllowAnonymous]
    public class HomeController : Controller
    {
        // GET: Home
        [AllowAnonymous]
        public ActionResult Home()
        {
            ReaderDal dal = new ReaderDal();
            List<Manga> l = (from x in dal.Manga where x.IsRemoved == false select x).ToList<Manga>();
            Random random = new Random();
            Manga m = null;
            if (l.Count != 0)
            {
                int randomNumber = random.Next(0, l.Count);
                m = l[randomNumber];
            }

            return View("Home",m);
        }
        [AllowAnonymous]
        public ActionResult About()
        {
            return View();
        }
        [AllowAnonymous]
        public ActionResult Contact()
        {
            return View();
        }
    }
}