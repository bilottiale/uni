var x1 >= 0;
var x2 >= 0;
var x3 >= 0;
var x4 >= 0;
var x5 >= 0;

maximize z:
    100*x1 + 155*x2 + 100*x3 + 105*x4 + 140*x5
    - (
        90000*(2*x1 + x2 + x3)
        + 100000*(3*x4 + 4*x5)
        + 50000*(x1 + 3*x2 + x3 + x4 + 0.5*x5)
        + 40000*(0.5*x1 + x2 + x3)
        + 30000*(0.2*x4 + 0.1*x5)
      ) / 3600;

subject to vincolo1: 2*x1 + x2 + x3 <= 60*3600;
subject to vincolo2: 3*x4 + 4*x5 <= 90*3600;
subject to vincolo3: x1 + 3*x2 + x3 + x4 + 0.5*x5 <= 130*3600;
subject to vincolo4: 0.5*x1 + x2 + x3 <= 70*3600;
subject to vincolo5: 0.2*x4 + 0.1*x5 <= 40*3600;

solve;

display x1, x2, x3, x4, x5, z;

end;
