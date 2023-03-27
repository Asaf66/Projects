# MATLAB
Building a model of LTI system
clear all
clc

a1=1;
a2=1;
a3=1;
a4=2;
a5=1;
a6=10;

t = linspace(-pi,pi,100);
x=cos(2*pi*t)+10*sin(20*pi*t);%אות כניסה

aH1=[1 1];%מכנה
b1=1;%מונה
aH2=[1 2 1];%מכנה
b2=1;%מונה
aH3=[exp(10) 0];%מכנה
b3=1;%מונה

H1=filter(b1,aH1,x);%שימוש בפקודה פילטר 
subplot(2,2,1)%
plot(t,x)
hold on %ממתין כדי לתת לגרף של הפילטר להיכנס 
plot(t,H1)
legend('Input Data','Filtered Data')%הצגת אות כניסה ואות מוצא 
title('y(t) of H1')%כותרת
grid on


H2=filter(b2,aH2,x);
subplot(2,2,2)
plot(t,x)
hold on
plot(t,H2)  
legend('Input Data','Filtered Data')
title('y(t) of H2')
grid on


H3=filter(b2,aH3,x);
subplot(2,2,3:4)
plot(t,x)
hold on
plot(t,H3)
legend('Input Data','Filtered Data')
title('y(t) of H3')
grid on

%-------------------------------------------%

%סעיף 4
a1=1;
a2=1;
a3=1;
a4=2;
a5=1;
a6=10;
H1= tf([0 1], [a2 a1])
H2= tf([0 1], [a5 a4 a3])
H3=tf([0 1],[ 0 exp(a6) 0])
F1=parallel(H3,H2)%במקביל
R=series(H1,F1) %בטור
F=R %המערכת הכוללת

%סעיף 5
m=[1 2.203e04 1];%מונה
n=[2.203e04 6.608e04 6.608e04 2.203e04 0];%מכנה
t = linspace(-pi,pi,100);
x=cos(2*pi*t)+10*sin(20*pi*t); %אות כניסה של סעיף 2
z=filter(m,n,x); %שימוש בפקודה פילטר   
plot(t,x)
hold on 
plot(t,z)
legend('Input Data','Filtered Data')
title('x(t) of F')
xlabel ('time')
ylabel('Amplitude')
grid on

%functions%

function H1 = filter1(a1,a2)
H1= tf([0 1], [a2 a1]);
end

function H2 = filter2(a3,a4,a5)
H2= tf([0 1], [a5 a4 a3]);
end

function H3 = filter3(a6)
H3=tf([0 1],[exp(a6) 0]);
end


