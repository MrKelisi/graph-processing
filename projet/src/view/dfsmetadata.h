#pragma once

#include <file/dotmetadata.h>
#include <algorithm/dfs.h>

class DFSMetaData : public DotMetaData {
    public:
        DFSMetaData(const DFS* dfs);

        virtual std::string getEdgeLabel(const Arete<EdgeData, VertexData>* edge) override;

        std::string getVertexBackground(const Sommet<VertexData>* vertex) override;

    private:
        const DFS* _dfs;
};