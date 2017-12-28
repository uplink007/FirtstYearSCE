using Manga_Reader.Dal;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Optimization;
using System.Web.Routing;
using System.Web.Services;

namespace Manga_Reader
{
    public class MvcApplication : System.Web.HttpApplication
    {
        protected void Application_Start()
        {

            //CHECK THIS

            Database.SetInitializer(new DropCreateDatabaseIfModelChanges<Dal.ReaderDal>());
           //Database.SetInitializer(new DropCreateDatabaseAlways<Dal.ReaderDal>());

            AreaRegistration.RegisterAllAreas();
            FilterConfig.RegisterGlobalFilters(GlobalFilters.Filters);
            RouteConfig.RegisterRoutes(RouteTable.Routes);
            BundleConfig.RegisterBundles(BundleTable.Bundles);
        }
      
    }


}
