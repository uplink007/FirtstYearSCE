using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Web;

namespace Manga_Reader.Models
{
    public class Manga
    {

        [Key]
        [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
        public int mid { get; set; }
        [Required(ErrorMessage = "Manga name is required")]
        [StringLength(50, ErrorMessage = "Manga Name should be 1-50 characters long", MinimumLength = 1)]
        public string Name { get; set; }
        [Required(ErrorMessage = "Author Name is required")]
        [StringLength(20, ErrorMessage = "Name should be 1-20 characters long", MinimumLength = 1)]
        public string Author { get; set; }
        [Required]
        public Boolean Status { get; set; }
        public Boolean IsRemoved { get; set; }
        public virtual ICollection<User> Bookmarked { get; set; }
        public virtual ICollection<Chapter> Chapters { get; set; }

        public Manga()
        {
            IsRemoved = false;
            Bookmarked = new List<User>();
            Chapters = new List<Chapter>();
        }
    }
}