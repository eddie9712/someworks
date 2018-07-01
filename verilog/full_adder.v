module full_adder(c,s,x,y,z);
output c,s;
input x,y,z;
assign s=z^(x^y);
assign c=x&y;
endmodule     
                           
                    
                         
                 
                 















