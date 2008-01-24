#!/bin/csh
cd /afs/cern.ch/user/d/dorigo/scratch0/CMSSW_1_7_0/src/
eval `scramv1 runtime -csh`
cd -
cp /afs/cern.ch/user/d/dorigo/scratch0/CMSSW_1_7_0/src/AnalysisExamples/L1PixelAnalyzer/test/RUN/HEDn.root .
cp /afs/cern.ch/user/d/dorigo/scratch0/CMSSW_1_7_0/src/AnalysisExamples/L1PixelAnalyzer/test/RUN/functionfileSS.root .
cp /afs/cern.ch/user/d/dorigo/scratch0/CMSSW_1_7_0/src/AnalysisExamples/L1PixelAnalyzer/test/RUN/TTMnS1.root .
cp /afs/cern.ch/user/d/dorigo/scratch0/CMSSW_1_7_0/src/AnalysisExamples/L1PixelAnalyzer/test/RUN/TTMnS2.root .
cp /afs/cern.ch/user/d/dorigo/scratch0/CMSSW_1_7_0/src/AnalysisExamples/L1PixelAnalyzer/test/RUN/TTMnS3.root .
cp /afs/cern.ch/user/d/dorigo/scratch0/CMSSW_1_7_0/src/AnalysisExamples/L1PixelAnalyzer/test/RUN/Hread.asc .
cp /afs/cern.ch/user/d/dorigo/scratch0/CMSSW_1_7_0/src/AnalysisExamples/L1PixelAnalyzer/test/RUN/Tread.asc .
cp /afs/cern.ch/user/d/dorigo/scratch0/CMSSW_1_7_0/src/AnalysisExamples/L1PixelAnalyzer/test/RUN/PTagQCD.asc .
cmsRun /afs/cern.ch/user/d/dorigo/scratch0/CMSSW_1_7_0/src/AnalysisExamples/L1PixelAnalyzer/test/RUN/TDAna_QCD_230-300_w.cfg
rfcp TDAna_QCD_230-300.root /castor/cern.ch/user/d/dorigo/TDAna/
rfcp T.asc /castor/cern.ch/user/d/dorigo/TDAna/T_QCD_230-300.asc
rfcp H.asc /castor/cern.ch/user/d/dorigo/TDAna/H_QCD_230-300.asc
rfcp tthdecays.asc /castor/cern.ch/user/d/dorigo/TDAna/QCD_230-300_decays.asc