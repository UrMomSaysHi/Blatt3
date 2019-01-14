#include <QCoreApplication>
#include "utilities.h"
#include "neuron.h"
#include "net.h"
#include "fileos.h"

#include <iostream>
#include <QDir>


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


    FileOS fos = FileOS();



    fos.vec_to_file(nn.weights_to_vec(), nn.topology, "asdasdasd.txt");

    Net aasdasfg = fos.import_Net("asdasdasdss.txt");

    return a.exec();

}
