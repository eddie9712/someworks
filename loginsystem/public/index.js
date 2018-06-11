$(document).ready(function()
    {
         
      $('#register').click(function()
    {     
      $(".container").animate(
      {
        'opacity':'0',
         'height':'0px'
         
       },1,
      function()   
      {    
        $('.register_mode').animate(
            {
              'opacity':'1',
              'top':'30%'
              
            },1000,)});
      
        });   
      });   
