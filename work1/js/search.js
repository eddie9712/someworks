$(document).ready(function()
{    
 $('#back').click(function()
  {  
    window.location.replace('./index.html');   
     });
 $('#clear').click(function()
    {   
      $('#search').val('');
      $('#block1').hide();
       $('#block2').hide(); 
     });
   $('input').keypress(function(e) {
    code = e.keyCode ? e.keyCode : e.which; // in case of browser compatibility
    if(code == 13) {
        e.preventDefault();
        // do something
        /* also can use return false; instead. */
        }
    }); 


    
    });  //end ready
