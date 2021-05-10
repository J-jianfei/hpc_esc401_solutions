clear all
clc
load("serial_out.txt");
load("omp_out.txt");

[serial_fit,gof1] = fit(serial_out(:,1),serial_out(:,2),"power1");
[omp_fit,gof2] = fit(omp_out(:,1),omp_out(:,2),"power1");

hold on
plot(serial_fit,serial_out(:,1),serial_out(:,2),'o');
plot(omp_fit,omp_out(:,1),omp_out(:,2),'g*');
 legend('serial output','serial fit','omp output','omp fit');
  xlabel('number of particles');
 ylabel('calculation time: sec');
 txt1 = evalc('serial_fit');
 txt2 = evalc('omp_fit');
 text(0,13,{txt1,txt2},'FontSize',8)
 title("execution time for different number of particles");
 saveas(gcf,"plot.png")
 
