$(document).ready(function()
{
  $('#pass button').click(function()
 {
   $.ajax({
    method:'get',
    url:"./get_data",
    data:{
      user:$('#pass input[name="user"]').val(),
      std:$('#pass input[name="std"]').val(),
      department:$('#pass input[name="department"]').val()
   }
    }); //end ajax
   });   //end click function

}) // end ready function
