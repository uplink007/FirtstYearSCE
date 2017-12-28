using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Web;

namespace Manga_Reader.Models
{
    public class Chapter
    {
        [Key]
        [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
        public int cid { get; set; }
        [Required(ErrorMessage = "Chapter Name is required")]
        [StringLength(50, ErrorMessage = "Chapter Name should be 1-50 characters long", MinimumLength = 1)]
        public string name { get; set; }
        public string Path { get; set; }
        public int PageNum { get; set; }
    }
}