#include "fileos.h"



FileOS::FileOS()
{

}

/*!
 * @brief writes a vector into the specified file
 *
 * @param v vector
 *
 * @param topology dimensions of the vector
 *
 * @param file_dir file directory
 */
void FileOS::vec_to_file(vector<vector<vector<double>>> v, vector<int> topology, string file_dir){
    // a stupid solution for stupid people

    ofstream myfile;
    myfile.open(file_dir);
    for(int i = 0; i < topology.size(); i++){
        myfile << topology[i] << " ";
    }
    myfile << "\n";

    for(int e1 = 0; e1 < v.size(); e1++){
        for(int e2 = 0; e2 < v[e1].size(); e2++){
            for(int e3 = 0; e3 < v[e1][e2].size(); e3++){
                myfile << v[e1][e2][e3] << endl;
            }
        }
    }
    myfile.close();
}

/*!
 * @brief reads the vector out of the file
 *
 * @param file_dir file directory
 *
 * @return vector
 */
vector<vector<vector<double>>> FileOS::file_to_vec(string file_dir){
    vector<vector<vector<double>>> result_vec;
    string line;
    ifstream myfile (file_dir);

    getline (myfile,line);

    //this part is maliciously copied from https://stackoverflow.com/questions/20659066/parse-string-to-vector-of-int

    stringstream iss( line );
    int number;
    vector<int> topology;
    while ( iss >> number ){
        topology.push_back( number );
    }


    for(int e1 = 0; e1 < topology.size()-1; e1 ++){
        result_vec.push_back(vector<vector<double>>());
        for(int e2 = 0; e2 < topology[e1] + 1; e2++){
            result_vec.back().push_back(vector<double>());
            for(int e3 = 0; e3 < topology[e1 + 1]; e3 ++){
                getline (myfile,line);
                result_vec.back().back().push_back(stod(line));
            }
        }
    }



    myfile.close();

    return(result_vec);

}

/*!
 * @brief reads the topology out of the file
 *
 * @param file_dir file directory
 *
 * @return topology
 */
vector<int> FileOS::get_topology(string file_dir){
    string line;
    ifstream myfile (file_dir);

    getline (myfile,line);

    //this part is maliciously copied from https://stackoverflow.com/questions/20659066/parse-string-to-vector-of-int
    stringstream iss(line);
    int number;
    vector<int> topology;
    while ( iss >> number ){
        topology.push_back( number );
    }

    return(topology);
}

/*!
 * @brief creates a Net out of the weights specified in the textfile
 *
 * @param file_dir file directory
 *
 * @return Net
 */
Net FileOS::import_Net(string file_dir){
    vector<int> topology = get_topology(file_dir);
    vector<vector<vector<double>>> weights = file_to_vec(file_dir);

    Net my_net = Net(topology, *sigmoid0, *dsigmoid0);
    my_net.vec_to_weights(weights);

    return(my_net);
}

/*!
 * @brief saves Neuronal Net in a file
 *
 * @param nn Neurnal Net
 *
 * @param file_dir file directory
 */
void FileOS::Net_to_file(Net net, string file_dir){
    vec_to_file(net.weights_to_vec(), net.topology, file_dir);
}
