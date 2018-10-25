# -----------------------------------------------------------------------------------------------------------------------------
# https://twiki.cern.ch/twiki/bin/view/CMSPublic/WorkBookCRAB3Tutorial  #**Up-to-date**
# https://twiki.cern.ch/twiki/bin/view/CMSPublic/CRAB3ConfigurationFile #
# https://twiki.cern.ch/twiki/bin/view/CMSPublic/CRAB3CheatSheet        #
#
# Environment setup:
#    cmsenv
#    source /cvmfs/cms.cern.ch/crab3/crab.sh
# To submit: 
#    crab submit -c crab_fcdanalysis_cfg.py
# To check status: 
#    crab status -d <CRAB-project-directory> [--jobids <comma-separated-list-of-jobs-and/or-job-ranges>]
# To kill jobs:
#    crab kill -d <CRAB-project-directory> [--jobids <comma-separated-list-of-jobs-and/or-job-ranges>]
# To retrieve output:
#    crab getoutput -d <CRAB-project-directory> [--jobids <comma-separated-list-of-jobs-and/or-job-ranges>]
# -----------------------------------------------------------------------------------------------------------------------------
from CRABClient.UserUtilities import config
from CRABClient.UserUtilities import getUsernameFromSiteDB


# Select dataset to crab over
number = 0 # starting at 0

# List of datasets
datasetnames = [
#'/NoBPTX/Commissioning2016-PromptReco-v1/RECO',
#'/MinimumBias/Commissioning2016-PromptReco-v1/RECO',
#'/HcalHPDNoise/Commissioning2016-PromptReco-v1/RECO',
#'/HcalNZS/Commissioning2016-PromptReco-v1/RECO',
#'/Cosmics/Commissioning2016-PromptReco-v1/RECO'
#'/JetHT/Run2017A-v1/RAW'
#'/HLTPhysics1/Run2017A-v1/RAW'
#'/MET/Run2017B-v1/RAW'
#'/JetHT/Run2017B-v1/RAW'
#'/MinimumBias/Run2017C-v1/RAW'
'/JetHT/Run2018D-v1/RAW'
]

# Storage path for output files - EOS specific
storagepath = '/store/user/'+getUsernameFromSiteDB()+'/FCDAnalysis'
#storagepath = '/store/group/dpg_hcal/comm_hcal/Noise/2017/' # DO NOT USE

# cmsRun file
psetname = 'fcdanalysis_cfg.py'

# Output filename
OutputFilename = 'fcdanalysis.root'

# Storage site of output files
#storageSite = 'T2_CH_CERN'
storageSite = 'T3_US_FNALLPC' # temporarily used UCSD T2

# White list sites
whiteList = ['']

# Black list sites
blackList = ['']

# -----------------------------------------------------------------------------------------------------------------------------
# No modifications below this line are necessary

import datetime
timestamp = datetime.datetime.now().strftime("_%Y%m%d_%H%M%S")


dataset = filter(None, datasetnames[number].split('/'))

config = config()

config.General.workArea        = "crabFCDAnalysis"
config.General.requestName     = dataset[0]+'_'+dataset[1]+'_'+dataset[2]+timestamp
config.General.transferOutputs = True
config.General.transferLogs    = True

config.JobType.pluginName  = 'Analysis'
config.JobType.psetName    = psetname 
config.JobType.outputFiles = [OutputFilename]
config.JobType.pyCfgParams = ['outputFile='+OutputFilename]


# DATA specific:
config.Data.inputDataset     = datasetnames[number]
config.Data.inputDBS         = 'global'
config.Data.splitting        = 'LumiBased'
config.Data.unitsPerJob      = 5 
config.JobType.numCores      = 4
#config.Data.ignoreLocality  = True
#config.Data.outLFNDirBase   = storagepath
config.Data.publication      = False
config.Data.outputDatasetTag = dataset[1]+'_'+dataset[2]+timestamp
#config.Data.lumiMask        = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Reprocessing/Cert_13TeV_16Dec2015ReReco_Collisions15_25ns_JSON.txt'
#config.Data.runRange        = '254231-260627'
#config.Data.runRange        = '260577-260578' #for test
#config.Data.lumiMask        = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Reprocessing/Cert_13TeV_16Dec2015ReReco_Collisions15_50ns_JSON.txt'
#config.Data.runRange        = '295606-295606'
#config.Data.runRange        = '295436-296174'
#config.Data.lumiMask        = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions17/13TeV/PromptReco/Cert_294927-297723_13TeV_PromptReco_Collisions17_JSON.txt'
#config.Data.runRange        = '297429-297429'
#config.Data.runRange        = '297666-297723'
#config.Data.runRange        = '300820-300901'#'300935-300935'
#config.Data.lumiMask        = '/afs/cern.ch/user/j/jaehyeok/work/HCAL/Reconstruction/CMSSW_10_0_0/src/HCALPFG/HcalTupleMaker/test/Cert_304797_13TeV_PromptReco_Collisions17_JSON.txt'
config.Data.runRange         = '323336-323345'

# -----------------------------------------------------------------------------------------------------------------------------
# JSON files are available at: /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/
# -----------------------------------------------------------------------------------------------------------------------------

config.Site.storageSite = storageSite

if not whiteList:
  config.Site.whitelist = whiteList

if not blackList:
  config.Site.blacklist = blackList

