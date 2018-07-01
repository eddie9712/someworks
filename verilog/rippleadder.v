module half_adder(output s,c,input x,y);
xor(s,x,y);
and(c,x,y);
endmodule
///fulladdetr halfadder////
module full_adder(output s,c,input x,y,z);
wire s1,c1,c2;
half_adder h1(s1,c1,x,y);
half_adder h2(s,c2,s1,z);
or g1(c,c2,c1); 
endmodule
module 4bits(output [0:3]sum,output c4,input [3:0]a,input [3:0]b,input c0);
wire c1,c2,c3;
full_adder f1(sum[0],c1,a[0],b[0],c0),
            f2(sum[1],c2,a[1],b[1],c1),
            f3(sum[2],c3,a[2],b[2],c2),
            f4(sum[3],c4,a[3],b[3],c3);
endmodule




