from tools.load import LoadMatrix
lm=LoadMatrix()
traindat = lm.load_numbers('../data/fm_train_real.dat')
testdat = lm.load_numbers('../data/fm_test_real.dat')
label_traindat = lm.load_labels('../data/label_train_multiclass.dat')

parameter_list = [[traindat,testdat,label_traindat],[traindat,testdat,label_traindat]]

def classifier_gnb_modular(fm_train_real=traindat,fm_test_real=testdat,label_train_multiclass=label_traindat):
	from shogun.Features import RealFeatures, Labels
	from shogun.Classifier import GNB

	feats_train=RealFeatures(fm_train_real)
	feats_test=RealFeatures(fm_test_real)
	labels=Labels(label_train_multiclass)

	gnb=GNB(feats_train, labels)
	gnb_train = gnb.train()
	output=gnb.classify(feats_test).get_labels()
	return gnb,gnb_train,output

if __name__=='__main__':
	print 'GNB'
	classifier_gnb_modular(*parameter_list[0])