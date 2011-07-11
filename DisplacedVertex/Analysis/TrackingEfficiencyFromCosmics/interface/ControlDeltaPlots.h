#ifndef CONTROLDELTAPLOTS_H
#define CONTROLDELTAPLOTS_H

#include <vector>
#include <TH1F.h>
#include "DataFormats/Math/interface/deltaPhi.h"
#include "Analysis/TrackingEfficiencyFromCosmics/interface/Utils.h"

/**
  * Fill a set of control plots for the differences between two tracks. 
  */
class ControlDeltaPlots
{
public:
  ControlDeltaPlots( edm::Service<TFileService> & fileService, const TString & name, const int sign = 1 ) :
    sign_(sign)
  {
    hDeltaPt_ =  utils::bookHistogram(fileService, name, "DeltaPt", "#Delta P_{T}", "[GeV/c]", 500, 0, 500);
    hDeltaEta_ = utils::bookHistogram(fileService, name, "DeltaEta", "#Delta #eta", "", 500, -6, 6);
    hDeltaPhi_ = utils::bookHistogram(fileService, name, "DeltaPhi", "#Delta #phi", "", 500, -6.4, 6.4);
    hDeltaDxy_ = utils::bookHistogram(fileService, name, "DeltaDxy", "|#Delta |dxy||", "cm", 1000, -500, 500);
    hDeltaDz_ =  utils::bookHistogram(fileService, name, "DeltaDz", "|#Delta |dz||", "cm", 1000, -100, 100);
    // hDeltaPt_ = fileService->make<TH1F>(name+"_DeltaPt",name+" DeltaPt",1000,-500,500);
    // hDeltaEta_ = fileService->make<TH1F>(name+"_DeltaEta",name+" DeltaEta",500,-6,6);
    // hDeltaPhi_ = fileService->make<TH1F>(name+"_DeltaPhi",name+" DeltaPhi",500,-6.4,6.4);
    // hDeltaDxy_ = fileService->make<TH1F>(name+"_DeltaDxy",name+" DeltaDxy",1000,-500,500);
    // hDeltaDz_ = fileService->make<TH1F>(name+"_DeltaDz",name+" DeltaDz",1000,-100,100);
  }
  template <class T1, class T2>
    void fillControlPlots(const T1 & track1, const T2 & track2)
  {
    hDeltaPt_->Fill(track1.pt() - track2.pt());
    // With sign = -1 back-to-back tracks have DeltaEta = 0
    hDeltaEta_->Fill(track1.eta() - sign_*track2.eta());
    hDeltaPhi_->Fill(reco::deltaPhi(track1.phi(), track2.phi()));
    // With sign = -1 back-to-back tracks have deltaDxy = 0
    hDeltaDxy_->Fill(track1.dxy() - sign_*track2.dxy());
    hDeltaDz_->Fill(track1.dz() - track2.dz());
  }

protected:
  TH1F *hDeltaPt_, *hDeltaEta_, *hDeltaPhi_, *hDeltaDxy_, *hDeltaDz_;
  int sign_;
};

#endif // CONTROLPLOTS_H