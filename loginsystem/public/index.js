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
              'top':'30%',
              'height':'40vh'
              
            },1000,)});
      
        }); 
      $("#back").click(function()    {
        $('.register_mode').animate(
       {
          'opacity':'0',
          'top':'70%',
          'height':'0%'
      
       },1000,
     function()  
     {
       $('.container').animate(
      {
        'opacity':1,
        'top':'30%',
        'height':'40vh'
      },1000,)})    
            
            });  //end of click function
$('#create').click(function()
  {
    event.preventDefault();  
    
    $.ajax({
            method: "get",
            url: "./ajax",
            data: {
            user:$("#create_data input[name='user']").val(),
            account:$("#create_data input[name='account']").val(),
            password:$("#create_data input[name='password']").val(),
            },
            success: 
              function(data)
            {
               
              $('.register_mode').animate({
                 'opacity':'0',
                 'height':'0'
               },1000,
                function()
              {
                 $('.success').animate(
              {
               'top':'50%',
               'left':'50%',
               'height':'40vh',
                'opacity':'1'
                },1000,)}
                ); 
            }  //end sucess
          });  //end ajax
      });   //end click function
  $('#back').click(function()
      {   
         $('.success').animate({
          'opacity':'0',
          'height':'0'
          },1000,
       function()
       {   
          $('.container').animate({
          'opacity':'1',
          'height':'40vh'
          },1000);
       
       });
      });
  });    //end ready function







