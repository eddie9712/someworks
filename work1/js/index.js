$(document).ready(function()
{
   $("#provide").click(function()
  {
    $("#first").show();     
     $("#second").show(); 
     $("#third").show(); 
     $("#change").html("<div class="col s5 push-s3" style="left:25%"><a class="waves-effect waves-light btn-small white red-text text-darken-3" style="width:30vw" id="finish">完成評分</a></div>")
  });
  $('#finish').click(function()
  { 
    

  });  
});  //end ready function
