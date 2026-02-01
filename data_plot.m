
data = readtable('data.csv');

x_acc = table2array(data(:,5));
y_acc = table2array(data(:,6));
z_acc = table2array(data(:,7));

n = length(x_acc);
num_sampling = 1:n;

plot(num_sampling,z_acc);
plot(num_sampling,y_acc);
plot(num_sampling,x_acc);
