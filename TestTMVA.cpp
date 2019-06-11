#include <stdio.h>
#include <string>

#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TROOT.h"

#include "TMVA/DataLoader.h"
#include "TMVA/Tools.h"

void TestTMVA()
{
	TMVA::Tools::Instance();
	
	(TMVA::gConfig().GetVariablePlotting()).fMaxNumOfAllowedVariablesForScatterPlots = 1000;
	
	TChain *TTChain = new TChain("condensedNTuple");
	//TChain *BGChain = new TChain("condensedNTuple");
	TChain *DYChain = new TChain("condensedNTuple");
	TChain *SingleTopChain = new TChain("condensedNTuple");
	TChain *DibosonChain = new TChain("condensedNTuple");
	
	for (int fragment = 1; fragment <= 36; fragment++)
		TTChain->Add((string("MC/condensed_TTJets_TuneZ2_7TeV-madgraph-tauola_00000_")
			+std::to_string(fragment)+string("_fragment.root")).c_str());
	for (int fragment = 1; fragment <= 36; fragment++)
		TTChain->Add((string("MC/condensed_TTJets_TuneZ2_7TeV-madgraph-tauola_00001_")
			+std::to_string(fragment)+string("_fragment.root")).c_str());
	for (int fragment = 1; fragment <= 36; fragment++)
		TTChain->Add((string("MC/condensed_TTJets_TuneZ2_7TeV-madgraph-tauola_010000_")
			+std::to_string(fragment)+string("_fragment.root")).c_str());
	for (int fragment = 1; fragment <= 36; fragment++)
		TTChain->Add((string("MC/condensed_TTJets_TuneZ2_7TeV-madgraph-tauola_010001_")
			+std::to_string(fragment)+string("_fragment.root")).c_str());
	for (int fragment = 1; fragment <= 36; fragment++)
		TTChain->Add((string("MC/condensed_TTJets_TuneZ2_7TeV-madgraph-tauola_010002_")
			+std::to_string(fragment)+string("_fragment.root")).c_str());
	for (int fragment = 1; fragment <= 36; fragment++)
		TTChain->Add((string("MC/condensed_TTJets_TuneZ2_7TeV-madgraph-tauola_010003_")
			+std::to_string(fragment)+string("_fragment.root")).c_str());
	for (int fragment = 1; fragment <= 36; fragment++)
		DYChain->Add((string("MC/condensed_DYJetsToLL_M-10To50_TuneZ2_7TeV-pythia6_00000_")
			+std::to_string(fragment)+string("_fragment.root")).c_str());
	for (int fragment = 1; fragment <= 36; fragment++)
		DYChain->Add((string("MC/condensed_DYJetsToLL_TuneZ2_M-50_7TeV-madgraph-tauola_00000_")
			+std::to_string(fragment)+string("_fragment.root")).c_str());
	for (int fragment = 1; fragment <= 36; fragment++)
		DYChain->Add((string("MC/condensed_DYJetsToLL_TuneZ2_M-50_7TeV-madgraph-tauola_010005_")
			+std::to_string(fragment)+string("_fragment.root")).c_str());
	for (int fragment = 1; fragment <= 36; fragment++)
		DYChain->Add((string("MC/condensed_DYJetsToLL_TuneZ2_M-50_7TeV-madgraph-tauola_010010_")
			+std::to_string(fragment)+string("_fragment.root")).c_str());
	for (int fragment = 1; fragment <= 36; fragment++)
		SingleTopChain->Add((string("MC/condensed_Tbar_TuneZ2_tW-channel-DR_7TeV-powheg-tauola_00000_")
			+std::to_string(fragment)+string("_fragment.root")).c_str());
	for (int fragment = 1; fragment <= 36; fragment++)
		SingleTopChain->Add((string("MC/condensed_T_TuneZ2_tW-channel-DR_7TeV-powheg-tauola_00000_")
			+std::to_string(fragment)+string("_fragment.root")).c_str());
	for (int fragment = 1; fragment <= 36; fragment++)
		SingleTopChain->Add((string("MC/condensed_T_TuneZ2_tW-channel-DR_7TeV-powheg-tauola_010000_")
			+std::to_string(fragment)+string("_fragment.root")).c_str());
	for (int fragment = 1; fragment <= 36; fragment++)
		DibosonChain->Add((string("MC/condensed_WJetsToLNu_TuneZ2_7TeV-madgraph-tauola_00000_")
			+std::to_string(fragment)+string("_fragment.root")).c_str());
	for (int fragment = 1; fragment <= 36; fragment++)
		DibosonChain->Add((string("MC/condensed_WJetsToLNu_TuneZ2_7TeV-madgraph-tauola_00001_")
			+std::to_string(fragment)+string("_fragment.root")).c_str());
	for (int fragment = 1; fragment <= 36; fragment++)
		DibosonChain->Add((string("MC/condensed_WJetsToLNu_TuneZ2_7TeV-madgraph-tauola_00002_")
			+std::to_string(fragment)+string("_fragment.root")).c_str());
	for (int fragment = 1; fragment <= 36; fragment++)
		DibosonChain->Add((string("MC/condensed_WJetsToLNu_TuneZ2_7TeV-madgraph-tauola_00003_")
			+std::to_string(fragment)+string("_fragment.root")).c_str());
	for (int fragment = 1; fragment <= 36; fragment++)
		DibosonChain->Add((string("MC/condensed_WW_TuneZ2_7TeV_pythia6_tauola_00000_")
			+std::to_string(fragment)+string("_fragment.root")).c_str());
	for (int fragment = 1; fragment <= 36; fragment++)
		DibosonChain->Add((string("MC/condensed_WZ_TuneZ2_7TeV_pythia6_tauola_00000_")
			+std::to_string(fragment)+string("_fragment.root")).c_str());
	for (int fragment = 1; fragment <= 36; fragment++)
		DibosonChain->Add((string("MC/condensed_ZZ_TuneZ2_7TeV_pythia6_tauola_00000_")
			+std::to_string(fragment)+string("_fragment.root")).c_str());
	
	printf("TTChain = %lld events\n",TTChain->GetEntries());
	printf("DYChain  = %lld events\n",DYChain->GetEntries());
	printf("SingleTopChain  = %lld events\n",SingleTopChain->GetEntries());
	printf("DibosonChain  = %lld events\n",DibosonChain->GetEntries());
	//getchar();
	
	TString outFileName("TMVA.root");
	TFile *outFile = new TFile(outFileName, "RECREATE");

	TMVA::Factory *factory = new TMVA::Factory("TopML", outFile, "V:Color");
	TMVA::DataLoader *dataLoader=new TMVA::DataLoader("MCTrainingSet");

	dataLoader->AddSignalTree(TTChain, 1.0);
	dataLoader->AddBackgroundTree(DYChain, 1.0);
	dataLoader->AddBackgroundTree(SingleTopChain, 1.0);
	dataLoader->AddBackgroundTree(DibosonChain, 1.0);
	
	dataLoader->AddVariable("jet1_pt",'F');
	dataLoader->AddVariable("jet1_eta",'F');
	dataLoader->AddVariable("jet1_phi",'F');
	dataLoader->AddVariable("jet1_E",'F');
	dataLoader->AddVariable("jet1_bTag",'F');
	
	dataLoader->AddVariable("jet2_pt",'F');
	dataLoader->AddVariable("jet2_eta",'F');
	dataLoader->AddVariable("jet2_phi",'F');
	dataLoader->AddVariable("jet2_E",'F');
	dataLoader->AddVariable("jet2_bTag",'F');
	
	dataLoader->AddVariable("lepton1_pt",'F');
	dataLoader->AddVariable("lepton1_eta",'F');
	dataLoader->AddVariable("lepton1_phi",'F');
	dataLoader->AddVariable("lepton1_E",'F');
	dataLoader->AddVariable("lepton1_charge",'F');
	//dataLoader->AddVariable("lepton1_isMuon",'I');
	
	dataLoader->AddVariable("lepton2_pt",'F');
	dataLoader->AddVariable("lepton2_eta",'F');
	dataLoader->AddVariable("lepton2_phi",'F');
	dataLoader->AddVariable("lepton2_E",'F');
	dataLoader->AddVariable("lepton2_charge",'F');
	//dataLoader->AddVariable("lepton2_isMuon",'I');
	
	dataLoader->AddVariable("met_pt",'F');
	dataLoader->AddVariable("met_phi",'F');
	
	/*
	dataLoader->AddVariable("top1_pt",'F');
	dataLoader->AddVariable("top1_eta",'F');
	dataLoader->AddVariable("top1_phi",'F');
	dataLoader->AddVariable("top1_E",'F');
	dataLoader->AddVariable("tbar1_pt",'F');
	dataLoader->AddVariable("tbar1_eta",'F');
	dataLoader->AddVariable("tbar1_phi",'F');
	dataLoader->AddVariable("tbar1_E",'F');

	dataLoader->AddVariable("top2_pt",'F');
	dataLoader->AddVariable("top2_eta",'F');
	dataLoader->AddVariable("top2_phi",'F');
	dataLoader->AddVariable("top2_E",'F');
	dataLoader->AddVariable("tbar2_pt",'F');
	dataLoader->AddVariable("tbar2_eta",'F');
	dataLoader->AddVariable("tbar2_phi",'F');
	dataLoader->AddVariable("tbar2_E",'F');

	dataLoader->AddVariable("top1_mass",'F');
	dataLoader->AddVariable("top2_mass",'F');
	*/

	dataLoader->AddVariable("top_pt",'F');
	dataLoader->AddVariable("top_eta",'F');
	dataLoader->AddVariable("top_phi",'F');
	dataLoader->AddVariable("top_E",'F');
	dataLoader->AddVariable("tbar_pt",'F');
	dataLoader->AddVariable("tbar_eta",'F');
	dataLoader->AddVariable("tbar_phi",'F');
	dataLoader->AddVariable("tbar_E",'F');

	dataLoader->AddVariable("WP_pt",'F');
	dataLoader->AddVariable("WP_eta",'F');
	dataLoader->AddVariable("WP_phi",'F');
	dataLoader->AddVariable("WP_E",'F');
	dataLoader->AddVariable("WP_mass",'F');
	dataLoader->AddVariable("WM_pt",'F');
	dataLoader->AddVariable("WM_eta",'F');
	dataLoader->AddVariable("WM_phi",'F');
	dataLoader->AddVariable("WM_E",'F');
	dataLoader->AddVariable("WM_mass",'F');

	dataLoader->AddVariable("top_mass",'F');

	TCut mycuts = ""; // Signal cut
	TCut mycutb = ""; // Background cut

	dataLoader->PrepareTrainingAndTestTree(mycuts, mycutb, "SplitMode=Random:V");
	
	//factory->BookMethod(TMVA::Types::kLikelihood,"LikelihoodD","!H:!V:!TransformOutput:PDFInterpol=Spline2:NSmoothSig[0]=20:NSmoothBkg[0]=20:NSmooth=5:VarTransform=Decorrelate");	
	factory->BookMethod(dataLoader,TMVA::Types::kCuts,"Cuts","V:VarTransform=N"); // Cuts
	factory->BookMethod(dataLoader,TMVA::Types::kLikelihood,"Likelihood","V:VarTransform=N"); // Projective likelihood estimator
	factory->BookMethod(dataLoader,TMVA::Types::kPDERS,"PDERS","V:VarTransform=N"); // PDE range-search approach
	//factory->BookMethod(dataLoader,TMVA::Types::kPDEFoam,"PDEFoam","V"); // PDE-Foam
	factory->BookMethod(dataLoader,TMVA::Types::kKNN,"kNN","V:VarTransform=N"); // k-Nearest Neighbour classifier
	//factory->BookMethod(dataLoader,TMVA::Types::kHMatrix,"HMatrix","V"); // H-Matrix discriminant
	//factory->BookMethod(dataLoader,TMVA::Types::kFisher,"Fisher","V"); // Fisher discriminants (linear discriminant analysis)
	//factory->BookMethod(dataLoader,TMVA::Types::kFDA,"FDA","V"); // Function discriminant analysis (FDA)
	//factory->BookMethod(dataLoader,TMVA::Types::kMLP,"MLP_ANN","V:NeuronType=tanh:VarTransform=N:NCycles=1000:HiddenLayers=N+10,N"); // ROOT neural network
	factory->BookMethod(dataLoader,TMVA::Types::kMLP,"MLP_ANN","V:VarTransform=N"); // ROOT neural network
	factory->BookMethod(dataLoader,TMVA::Types::kSVM,"SVM","V:VarTransform=N"); // Support Vector Machine
	factory->BookMethod(dataLoader,TMVA::Types::kBDT,"BDT","V"); // Boosted Decision Tree
	factory->BookMethod(dataLoader,TMVA::Types::kRuleFit,"RuleFit","V"); // Predictive learning via rule ensembles
	
	//factory->OptimizeAllMethodsForClassification(); // Takes too much time!
	factory->TrainAllMethods();
	factory->TestAllMethods();
	
	factory->EvaluateAllMethods();

	outFile->Close();

	Bool_t useTMVAStyle = true;
	TMVA::TMVAGlob::Initialize(useTMVAStyle);

	TString dataset("MCTrainingSet");
	TMVA::StatDialogMVAEffs *gGui = new TMVA::StatDialogMVAEffs(dataset,gClient->GetRoot(), 1640, 363849);

	TString histFileName("TMVA.root");
	TFile *histFile = new TFile(histFileName,"READ");
	gGui->ReadHistograms(histFile);
	gGui->SetFormula("S/sqrt(S+B)");
	gGui->UpdateSignificanceHists();
	gGui->DrawHistograms();
	gGui->RaiseDialog();
}
