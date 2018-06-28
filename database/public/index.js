$(document).ready(function()
{
  
  $('#pass button').click(function(event)
 {
    event.preventDefault(); 
   $.ajax({
    method:'get',
    url:"./get_data",
    data:{
      user:$('#pass input[name="user"]').val(),
      std:$('#pass input[name="std"]').val(),
      department:$('#pass input[name="department"]').val()
   },
   success:function(data)
  {
     if(data==1)
     {
     $('#check').show();
      }
      else if(data==2)
     {
       $('#check2').show();
     }
     $('.container').hide();  
   } 
    }); //end ajax
   });   //end click function
    
}) // end ready function
