using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Web;
using Manga_Reader.Models;

namespace Manga_Reader.Dal
{
    public class ReaderDal : DbContext
    {
        public DbSet<User> Users { get; set; }
        public DbSet<Manga> Manga { get; set; }
        public DbSet<Chapter> Chapters { get; set; }



        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
            base.OnModelCreating(modelBuilder);
            modelBuilder.Entity<User>().ToTable("tblUsers");
            modelBuilder.Entity<Manga>().ToTable("tblManga");
            modelBuilder.Entity<Chapter>().ToTable("tblChapters");

            modelBuilder.Entity<User>().HasMany(x => x.Bookmarks).WithMany(y => y.Bookmarked).Map(m =>
            {
                m.ToTable("tlsBookmarks");
                m.MapLeftKey("uid");
                m.MapRightKey("mid");
            });

        }

    }
}