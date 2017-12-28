using Manga_Reader.Dal;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Web;

namespace Manga_Reader.Models
{
    public enum Permissions { Guest,Member, Uploader, Admin };
    public class User
    {

        [Key]
        [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
        public int uid { get; set; }
        [Required(ErrorMessage ="Username is required")]
        [StringLength(10,ErrorMessage ="Username should be 3-10 characters long",MinimumLength =3)]
        public string UserName { get; set; }
        [Required(ErrorMessage = "Password is required!")]
        [StringLength(100, ErrorMessage = "Password should be atleast 8 characters long", MinimumLength = 8)]
        public string Password { get; set; }
        [Required]
        public Permissions Permission { get; set; }
        public virtual ICollection<Manga> Bookmarks { get; set; }


        public User()
        {
            Permission = Permissions.Member;
            Bookmarks = new List<Manga>();
        }




       


    }
}