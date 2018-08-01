var value1=0;
var value2=0;
var value3=0;
var agree=0;
$(document).ready(function()
{
   $("#provide").click(function()
  {
     $("#first").show();     
     $("#second").show(); 
     $("#third").show();
     $("#finish").show();
     $("#provide").hide();
     
  });
   $('#finish').click(function()
  { 
    var myPromise= new Promise((resolve,reject)=>{
      value1=$('#range1').val();
       value2=$('#range2').val();
        value3=$('#range3').val();
        resolve("sucess");
    });
    myPromise.then((sucess)=>{
     $('.cardtitle1').text(value1);
     $('.cardtitle2').text(value2);
     $('.cardtitle3').text(value3);
     $('#changeTotext').html("恭喜成為第23位訪客。<br>你的付出，讓成大變得更好");
     $('#finish').html('<a class="waves-effect waves-light btn-small white red-text text-darken-3" style="width:35vw">順便寫心得</a>');
     $('#change>div').css("left","23%");
     $('.next').show();
    });    
  }); //end click "finish" 
   $('.next').click(function()
    {
      $('#change').hide();
      $('#changeTotext').hide();
      $('.next').html('');
    });
   $('#options').click(function()
  {
    $('.collection').show();  

  });
   $('.back').click(function()
  {     
   $('.collection').css("height","0");
   $('.collection').css("width","0");
   $('.collection').css("left","5vw");
  });
   $('#up').click(function()
  {
     agree++;
     $('#agree').text(agree);


  });
  $('#down').click(function()
  {
     if(agree!=0)
    {
      agree--; 
      $('#agree').text(agree);
    }     
    
  });  
});  //end ready function
