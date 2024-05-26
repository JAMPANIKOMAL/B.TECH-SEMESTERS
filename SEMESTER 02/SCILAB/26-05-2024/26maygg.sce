clc; clear; clf;

// Define the system of differential equations (y'=y2, y2'=-y1/2+5y2/2)
function dx = f(t, x)
  // Unpack the state vector x (y1, y2)
  y1 = x(1);
  y2 = x(2);

  // Define the derivatives (dx1, dx2)
  dx(1) = y2;  // y' = y2
  dx(2) = (-1/2)*y1 + (5/2)*y2;  // y2' = -y1/2 + 5y2/2
endfunction

// Initial conditions (y1=6, y2=-1 at t=3)
y0 = [6; -1];
t0 = 3;

// Solve ODE for a short interval (t=3 to 4)
sol_short = ode(y0, t0, 4, f);  // Solve from t=3 to t=4

// Display solution for the short interval (optional, commented out)
// disp('Solution for t=3 to 4:');
// disp(sol_short(1,:));  // Display y1 values only (optional)

// Define a longer time interval for plotting (t=4 to 10 with 0.5 increment)
t_long = 4:0.5:10;

// Solve ODE for the longer interval
sol_long = ode(y0, t0, t_long, f);

// Plot the solution (y1 vs t)
plot(t_long, sol_long(1,:));
xlabel('t');
ylabel('y1');
title('Solution of y^2-5y^1+y=0 (y1 vs t)');
