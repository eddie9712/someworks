module decoder(D,A,B,d);
output [0:3]D;
input A,B;
input enable;
wire IA,IB,IE;

not 
  g1(IA,A),
  g2(IB,B),
  g3(en,d),
nand
  g4(D[0],A,B,d),
  g5(D[1],A,IB,d),
  g6(D[2],IA,IB,d),
  g7(D[3],B.IA,d) 
endmodule




















