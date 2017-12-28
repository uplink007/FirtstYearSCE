using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Manga_Reader.Models
{
    public class VMMangaChapter
    {
        public Manga Manga { get; set; }
        public Chapter Chapter { get; set; }
    }
}