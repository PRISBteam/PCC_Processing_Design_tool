﻿///================================ DCC Processing module ===================================================================================///
///========================================================================================================================================///
/** The function in this library generate quasi-random or non-random processes of changes in the elements of the pre-constructed          ///
*   discrete sell complex (DCC) with the whole set of incidence and adjacency martices                                       **/         ///
///=====================================================================================================================================///

/// Attached user-defined C++ libraries:
///-------------------------------------
#include "Processing_Functions.h"
///-------------------------------------

using namespace std;
using namespace Eigen;

/// User-defined function definitions:
//std::vector<unsigned int> VectorReader(char* FilePath);

/// =============== PROCESSING MODULE ============= ///
std::vector<vector<unsigned int>> DCC_Processing(std::vector<unsigned int>  &special_faces_sequence, std::vector<unsigned int>  &ordinary_faces_sequence, const string P_type, double design_number) {
/// sface_design :: A list of special_faces_sequence as an output of the module. The first line here is always the random case (zero-design), then following Smax (1-sequence) and Smin (2-sequence), and then all the designs in between Smax and Smin
// CellNumbs :: vector components: [0] - Nodes number, [1] - Edges number, [2] - Faces number, [3] - Grains number
// Maximal fraction (max_sFaces_fraction) for simulation loop max_sFaces_fraction = [0,1]
// State_Vector in the form : [Element index] - > [Type]
    vector<unsigned int> State_sVector(CellNumbs.at(2),0); // State vector filling with zeros

/// Type of the Processing tool from config.txt (const_cast for processing type; const_cast for output directory)
char* stype = const_cast<char*>(P_type.c_str()); char* odir = const_cast<char*>(output_folder.c_str());
char simulation_type = *stype;
/// Cases for Processing types
    if (simulation_type == 'R') { //  Random generation case
        Processing_Random(State_sVector, special_faces_sequence, max_sFaces_fraction);
        special_face_design.push_back(special_faces_sequence);

    } ///End of 'R' type simulations
    else if (simulation_type == 'S' && design_number == 1) { // Maximum entropy production
        Processing_Random(State_sVector, special_faces_sequence, max_sFaces_fraction);
        special_face_design.push_back(special_faces_sequence);
        cout << "Processing_Random - successfully finished" << endl;

        std::fill(State_sVector.begin(), State_sVector.end(), 0);
        special_faces_sequence.clear();
        Processing_maxEntropy(State_sVector, special_faces_sequence);
        special_face_design.push_back(special_faces_sequence);
        cout << "Processing_maxEntropy - successfully finished" << endl;

    } ///End of 'R+S' type simulations

    else if (simulation_type == 'S' && design_number == 2) { // Maximum entropy production
        Processing_Random(State_sVector, special_faces_sequence, max_sFaces_fraction);
        special_face_design.push_back(special_faces_sequence);
        cout << "Processing_Random - successfully finished" << endl;
        Processing_maxEntropy(State_sVector, special_faces_sequence);
        cout << "Processing_maxEntropy - successfully finished" << endl;
        special_face_design.push_back(special_faces_sequence);
//        Processing_minEntropy(State_sVector, special_faces_sequence);
//        cout << "Processing_minEntropy - successfully finished" << endl;
//        sface_design.push_back(special_faces_sequence);

    } ///End of 'S' type simulations
    else if (simulation_type == 'S' && design_number > 2) { // Maximum entropy production
        Processing_Random(State_sVector, special_faces_sequence, max_sFaces_fraction);
        cout << "Processing_Random - successfully finished" << endl;
        special_face_design.push_back(special_faces_sequence);
        Processing_maxEntropy(State_sVector, special_faces_sequence);
        cout << "Processing_maxEntropy - successfully finished" << endl;
        special_face_design.push_back(special_faces_sequence);
//        Processing_minEntropy(State_sVector, special_faces_sequence);
//        cout << "Processing_minEntropy - successfully finished" << endl;
//        sface_design.push_back(special_faces_sequence);

        for (int it = 3; it < design_number; ++it) {
            //ip_index = Smax - Smin / (design_number - 1.0);
            //int Processing_ipIndex(std::vector<unsigned int> &S_Vector, std::vector<unsigned int> &s_faces_sequence, int index_type, double ip_index) {
            }
    } ///End of 'S' type simulations

    else cout << "ERROR [HAGBsProbability3D] : unknown simulation type - please replace with 'R', 'S' or 'I'..!" << endl;

    return special_face_design;
} /// The end of HAGBsProbability3D()

/// ================================== Related functions ==================================///

/// Heap
// (1)    cout << std::numeric_limits<long unsigned int>::max() << endl;

// (2) ofstream NONStructGlCoordOut; NONStructGlCoordOut.open("C:VAnRes\\(MFE21)GNC_NONStructured.txt", ios::trunc);

//(3) ARCHIVE testing output  //   cout << "The number of columns in the created matrices:\t" << "\tANS --\t" << ANS.cols() << "\tAES --\t" << AES.cols()<< "\tAFS --\t" << AFS.cols() << "\tAGS --\t" << AGS.cols() << "\tENS --\t" << ENS.cols() << "\tFES --\t" << FES.cols() << "\tGFS --\t" << GFS.cols() << endl;




/*
 *     /// Ordinary face sequence (!!works!!)
    ordinary_faces_sequence.clear();
    for (auto  itr = State_sVector.begin(); itr != State_sVector.end(); ++itr)
        if (*itr == 0) ordinary_faces_sequence.push_back(distance(State_sVector.begin(), itr));

 *
 *
 * else if (*stype == 'D') { // DDRX recrystalisation process
        Processing_DDRX(State_sVector, special_faces_sequence);
    } /// End of 'D' type simulations

    else if (*stype == 'X') { // structural index-based calculation
        /// Loop over all the index values
        enum index_types { Smin = 0, ip_ind, p_star, labda_ind};
        /// Actual value of the index !!! (move after to config.txt!)
        int index_type = Smin;

        int ip_stepsnumb = 1;
        double ip_index = 1.0, dip = 1.0;
        /// Informativeness
        if (index_type == ip_ind) {
            int ip_stepsnumb = 100;
            double ip_index = -1, dip = 2.0 / ip_stepsnumb; // ip index can changes from -1 to 1
        }

        for (int index = 0; index < ip_stepsnumb; ++index) {
             Processing_ipIndex(State_sVector, special_faces_sequence, index_type, ip_index);

            ip_index += dip; // index requested value increasing
        } // end for ( index < ip_stepnumb)
    } /// End of 'X' (ip index) type of simulations

   else if (*stype == 'E') { // Experimental data
        Processing_ExperimentalData(State_Vector, special_faces_sequence, max_sFaces_fraction, number_of_types, CellNumbs, paths);

        /// ====== Reading from file instead of DCC_Processing3D ( ) if it is off ============>
        string SFS_path = in + "Smax/SpecialGrainBoundaries.txt"s;
        cout << "-----------------------------------------------------------------------------------------------------------------------------"s << endl;
        cout << "Warning!!: special_faces_sequence successfully loaded from file:\t"s << SFS_path << " because the Processing is OFF"s << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------"s << endl;
        char* SFS_dir = const_cast<char*>(SFS_path.c_str());
        special_faces_sequence = VectorReader(SFS_dir); //all Faces
        for (auto itr: special_faces_sequence) State_Vector.at(itr) = 1;
    }
*/
