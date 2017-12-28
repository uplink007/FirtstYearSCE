using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Manga_Reader.Models
{
    public class VMMangaList
    {
        public ICollection<Manga> MangaList { get; set; }

        public User usr { get; set; }
    }
}