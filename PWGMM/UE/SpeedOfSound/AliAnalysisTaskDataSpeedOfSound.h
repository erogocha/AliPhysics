/* Copyright(c) 1998-1999, ALICfalseriment at CERN, All rights reserved. */
/* See cxx source for full Copyright notice */
/* Add a description of your MPI analysis */

#ifndef AliAnalysisTaskDataSpeedOfSound_H
#define AliAnalysisTaskDataSpeedOfSound_H

class AliESDtrackCuts;
class AliESDEvent;
class TList;
class TH1F;
class TH2F;
class TH3F;
class TProfile;

#include "AliAnalysisTaskSE.h"
#include "AliEventCuts.h"
#include "AliGenEventHeader.h"
#include "AliMCEvent.h"
#include "AliMCEventHandler.h"
#include "AliMCParticle.h"
#include "AliMultSelection.h"
#include "AliStack.h"
#include "AliVEvent.h"
#include "TParticle.h"

class AliAnalysisTaskDataSpeedOfSound : public AliAnalysisTaskSE {
 public:
  AliAnalysisTaskDataSpeedOfSound();
  AliAnalysisTaskDataSpeedOfSound(const char* name);
  virtual ~AliAnalysisTaskDataSpeedOfSound();
  virtual void UserCreateOutputObjects();
  virtual void UserExec(Option_t* option);
  virtual void Terminate(Option_t* option);
  void AnalyzeRecEvent(int& rec_nch, std::vector<float>& vec_rec_pt) const;
  void DCAxyDistributions() const;
  void TrackingEfficiency() const;
  void AnalyzeMCevent(int& true_nch, std::vector<float>& vec_true_pt) const;
  void DetectorResponse(const int& true_nch, const int& rec_nch) const;
  void RecMultiplicityDistributions(const int& rec_nch,
                                    const std::vector<float>& vec_rec_pt) const;
  void TrueMultiplicityDistributions(
      const int& true_nch, const std::vector<float>& vec_true_pt) const;
  void MultiplicityDistributions(const int& rec_nch,
                                 const std::vector<float>& vec_rec_pt) const;
  void SetV0Mmin(double V0Mmin) { fV0Mmin = V0Mmin; }  // Set V0M min value
  void SetV0Mmax(double V0Mmax) { fV0Mmax = V0Mmax; }  // Set V0M max value
  void SetUseMC(bool mc = false) { fUseMC = mc; }      // use to analyse MC data
  void SetTrackCuts(bool TPConly = true) { fIsTPConly = TPConly; }
  void SetTrigger(UInt_t offlineTriggerMask = AliVEvent::kINT7) {
    fTrigger = offlineTriggerMask;
  }
  bool HasRecVertex();

 protected:
 private:
  AliESDEvent* fESD;
  AliEventCuts fEventCuts;
  AliStack* fMCStack;
  AliMCEvent* fMC;
  bool fUseMC;
  bool fIsTPConly;
  UInt_t fTrigger;
  AliAnalysisFilter* fTrackFilter;
  AliAnalysisFilter* fTrackFilterwoDCA;
  TList* fOutputList;
  double fEtaCut;
  double fPtMin;
  double fV0Mmin;
  double fV0Mmax;
  double ftrackmult08;
  double fv0mpercentile;
  float fdcaxy;
  float fdcaz;
  AliMultSelection* fMultSelection;
  TH2D* hNchUCvsV0M;
  TH1F* hV0Mmult;
  TH2F* hTrackletvsV0M;
  TProfile* pPtvsNch[3];
  TH2D* hPtvsNch[3];
  TProfile* pPtvsNch05;
  TH2D* hPtvsNch05;
  TH1F* hTrueVtxZ;
  TH2F* hTrueNchvsV0M_UC;
  TH2F* hRecNchvsV0M_UC;
  TH2D* hNchResponse;
  TH2D* hPtTruePrivsV0M;
  TH2D* hPtRecPrivsV0M;
  TH2D* hRecNchvsRecPt05;
  TH2D* hTrueNchvsTruePt05;
  TH2D* hRecNchvsRecPt[3];
  TH2D* hTrueNchvsTruePt[3];
  TH2F* hDCAxyPri[3];
  TH2F* hDCAxyWeDe[3];
  TH2F* hDCAxyMaIn[3];
  TH2F* hDCAxyData[3];
  TH2F* hTrueNchHM;
  TH2F* hTrueNchHMWithTrigger;
  TH2F* hTrueNchHMWithEventCuts;
  TH2F* hTrueNchHMWithVtxSel;

  AliAnalysisTaskDataSpeedOfSound(
      const AliAnalysisTaskDataSpeedOfSound&);  // not implemented
  AliAnalysisTaskDataSpeedOfSound& operator=(
      const AliAnalysisTaskDataSpeedOfSound&);  // not implemented

  ClassDef(AliAnalysisTaskDataSpeedOfSound, 3);
};
#endif
