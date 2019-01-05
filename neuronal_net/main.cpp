#include <QCoreApplication>
#include "utilities.h"
#include "neuron.h"
#include "net.h"
#include "fileos.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << sigmoid0(1) << endl;

    Neuron nne = Neuron(*sigmoid0, *dsigmoid0, 4);

    cout << nne.f(-1) << endl;

    vector<int> n_top = {3,4,7,4,2};

    vector<double> x_in = {3,4,7};
    vector<double> y_out = {3,4};

    Net nn = Net(n_top, *sigmoid0, *dsigmoid0);

    cout << nn.predict(x_in)[1];
    nn.train(x_in, y_out, 0.2, 0.1);

    FileOS fos = FileOS();

    //fos.vec_to_file(nn.weights_to_vec(), nn.topology);
    Net aasdasfg = fos.import_Net("example.txt");

    return a.exec();

}
