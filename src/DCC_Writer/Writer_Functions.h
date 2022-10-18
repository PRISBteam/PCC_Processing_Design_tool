///================================ A part of the DCC Writer module ====================================================================///
///=====================================================================================================================================///
/** The library contains functions for the formatted output of various kind of data generated by other modules                         **/
///===================================================================================================================================///
//Output directory
string odir = output_folder;
//char* odir = const_cast<char*>(output_folder.c_str());

int DCC_sequences_Writer(std::vector<unsigned int> const  &special_faces_sequence, std::vector<unsigned int> const &kinetic_faces_sequence) {
/// output special_Face_sequence to file
    ofstream OutSfaces_file, OutOfaces_file; // Special and Ordinary faces sequence output
/// Output to file Special and Ordinary faces order :: tess - means "numeration of Faces start with 1 instead of 0 like in the NEPER output"
    // Random
    OutSfaces_file.open(output_folder + "RandomSpecialFaces.txt"s, ios::trunc);
    if (OutSfaces_file) { //        OutSGBfile << "Global numbers (in DCC) of special grain boundaries with the fraction " << special_faces_sequence.size()/ CellNumbs.at(2) << endl;
        for (auto rvit: special_face_design.at(0)) OutSfaces_file << rvit + 1 << endl; /// vit + 1 !!! for compatibility with the Neper output
        cout << "(1) Random special faces_sequence has been successfully written in " << output_folder + "RandomSpecialFaces.txt"s << endl;
        OutSfaces_file.close();
    } else cout << "Error: No such a directory for\t" << output_folder << "RandomSpecialFaces.txt"s << endl;
    // Smax
 if (design_number > 0) {
    OutOfaces_file.open(output_folder + "SmaxSpecialFaces.txt"s, ios::trunc);
    if (OutOfaces_file) {
        for (auto smvit: special_face_design.at(1))
            OutOfaces_file << smvit + 1 << endl; /// vit + 1 !!! for compatibility with the Neper output
        cout << "(2) Maximum conf entropy faces_sequence has been successfully written in " << output_folder
             << "SmaxSpecialFaces.txt"s << endl;
        OutOfaces_file.close();
    }
    } else cout << "Error: No such a directory for\t" << output_folder << "SmaxSpecialFaces.txt"s << endl;
/// sface_design

    /// output cracked_Face_sequence to file
    ofstream OutCFSfile; // Special Faces sequence output
    /// Output to file Cracked Faces order :: tess - means "numeration of Faces start with 1 instead of 0 like in the NEPER output"
    OutCFSfile.open(odir + "tess_CrackedGrainBoundaries.txt"s, ios::trunc);
    if (OutCFSfile) {
//        OutSGBfile << "Global numbers (in DCC) of cracked grain boundaries with the fraction " << special_faces_sequence.size()/ CellNumbs.at(2) << endl;
        for (auto vit: kinetic_faces_sequence)
            OutCFSfile << vit + 1 << endl; /// vit + 1 !!! for compatibility with the Neper output
//        { if (unsigned int numerator = 0; numerator < max_cFaces_fraction*CellNumbs.at(2)) OutCFSfile << vit + 1 << endl; ++numerator; }
        OutCFSfile.close();
    } else cout << "Error: No such a directory for\t" << output_folder << "CrackedGrainBoundaries.txt"s << endl;

    return 0;
}