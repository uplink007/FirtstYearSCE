using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Routing;

namespace Manga_Reader
{
    public class RouteConfig
    {
        public static void RegisterRoutes(RouteCollection routes)
        {
            routes.IgnoreRoute("{resource}.axd/{*pathInfo}");


            routes.MapRoute(
                name: "Home",
                url: "",
                defaults: new { controller = "Home", action = "Home", id = UrlParameter.Optional }
            );


            routes.MapRoute(
                name: "About",
                url: "About",
                defaults: new { controller = "Home", action = "About", id = UrlParameter.Optional }
            );

            routes.MapRoute(
                name: "Contact",
                url: "Contact",
                defaults: new { controller = "Home", action = "Contact", id = UrlParameter.Optional }
            );


            routes.MapRoute(
                name: "AddManga",
                url: "AddManga",
                defaults: new { controller = "Manga", action = "AddManga", MangaName = "", ChapterName = "" }
            );

            routes.MapRoute(
                name: "SubmitManga",
                url: "Manga/Submitted",
                defaults: new { controller = "Manga", action = "SubmitManga"}
            );

            routes.MapRoute(
                name: "MangaList",
                url: "Manga",
                defaults: new { controller = "Manga", action = "MangaList", MangaName = "", ChapterName = "" }
            );


            routes.MapRoute(
                name: "ViewManga",
                url: "Manga/{MangaID}",
                defaults: new { controller = "Manga", action = "ViewManga", MangaID = 0, ChapterID = 0 }

            );

            routes.MapRoute(
                name: "ViewChapter",
                url: "Manga/{MangaID}/{ChapterID}",
                defaults: new { controller = "Chapter", action = "ViewChapter", MangaID = 0, ChapterID = 0 }

            );

            routes.MapRoute(
                name: "RemoveManga",
                url: "RemoveManga",
                defaults: new { controller = "Manga", action = "RemoveManga" }

            );

            routes.MapRoute(
                name: "Default",
                url: "{controller}/{action}/{id}",
                defaults: new { controller = "Home", action = "Index", id = UrlParameter.Optional }
            );
        }
    }
}
