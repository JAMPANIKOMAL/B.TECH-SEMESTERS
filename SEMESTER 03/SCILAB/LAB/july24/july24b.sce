//To find the root of  y=x^3 - 4*x - 9

clc,clear;
function c=bisection(f, a, b, epsilon)
 fa = f(a);  fb = f(b);    // evaluate function at interval endpoints
 c = (a+b)/2;              // get midpoint
// check that f changes sign:
 if ( sign(fa) == sign(fb) )
   error('error in bisection: f(a), f(b) have the same sign!');
 end
 // print header for output table:
 printf('   [ %6s, %6s ] %8s %8s\n','a','b','c','fc')
 while ( (b-a)/2 > epsilon )        // loop til desired accuracy is reached
   fc = f(c);                           // evaluate f at midpoint
   printf('   [ %6.4f, %6.4f ] %8.4f %8.4f\n',a,b,c,fc)
   if ( sign ( fc ) == sign ( fa ) )    // shrink the bracketing interval
     a = c;  fa = fc;
   elseif ( sign ( fc ) == sign ( fb ) )
     b = c;  fb = fc;
   end
   c = (a+b)/2;                         // get new midpoint
 end  // while
endfunction

// define the function whose root we want to find:
function y=myfunc(x)
  y = x^3 - 4*x - 9
endfunction
