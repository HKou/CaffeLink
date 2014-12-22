
#ifndef CLNETS_HPP
#define	CLNETS_HPP

#include "caffe/caffe.hpp"

template <typename Dtype>
class CLnets {
public:
    explicit CLnets();
    virtual ~CLnets(){};
    
    caffe::Net<Dtype> *net;
    
    bool exportNet(char* path);

    bool prepareNetString(char* paramStr);
    bool prepareNetFile(char* path);
    void loadNet(char* path);
    
    void testNet();
    void trainNet(caffe::SolverParameter *param, int trainMode, char* path);
    
    void printNetInfo();

    int getLayerNum()
    {
        return net->layers().size();
    }
    bool getTopBlobSize(int** dims, int* dimSize, int layerIdx);
    bool getBottomBlobSize(int** dims, int* dimSize, int layerIdx);
    bool getParamBlobSize(int** dims, int* dimSize, int layerIdx);
    bool getInputSize(int** dims, int* dimSize);
    
    bool getTopBlob(Dtype** data, int layerIdx, int blobIdx);
    bool getBottomBlob(Dtype** data, int layerIdx, int blobIdx);
    bool getParamBlob(Dtype** data, int layerIdx, int blobIdx);
    
    bool setTopBlob(Dtype** data, int layerIdx, int blobIdx);
    bool setBottomBlob(Dtype** data, int layerIdx, int blobIdx);
    bool setParamBlob(Dtype** data, int layerIdx, int blobIdx);    
    bool setInput(Dtype **input);    
    
    
private:
    static Dtype varType;  
    
    bool getLayBlobSize(int** dims, int* dimSize, std::vector<caffe::Blob<Dtype>*> blobs);
    
    DISABLE_COPY_AND_ASSIGN(CLnets);
};

#endif	/* CLNETS_HPP */
