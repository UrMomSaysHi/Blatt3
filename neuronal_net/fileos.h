#ifndef FILEOS_H
#define FILEOS_H
#include <iostream>
#include <fstream>
#include <vector>

#include "net.h"
#include "utilities.h"
#include <sstream>

using namespace std;

class FileOS
{
public:
    FileOS();
    void vec_to_file(vector<vector<vector<double>>> v, vector<int> topology, string file_dir);
    vector<vector<vector<double>>> file_to_vec(string file_dir);
    vector<int> get_topology(string file_dir);
    Net import_Net(string file_dir);
    void Net_to_file(Net net, string file_dir);
};



#endif // FILEOS_H
