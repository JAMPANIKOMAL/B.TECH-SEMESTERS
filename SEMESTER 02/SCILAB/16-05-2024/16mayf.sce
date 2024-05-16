clc
clear

 u1 = [3 0 4]
u2 = [-1 0 7]
u3 = [2 9 11]

U = [u1; u2; u3]

[r, c] = size(U)

//[m n]= size (a);
q = zeros (r,c);
r = zeros (c,c);
for j=1: c
    v= U(:,j)
    for i =1:j -1
        r(i,j)=q(:,i)'*U(:,j)
        v=v-r(i,j)*q(:,i)
    end
    r(j,j)= norm(v)
    q(:,j)=v/r(j,j)
    disp(v, ' v=' )
    disp(q, ' q=' )
end
