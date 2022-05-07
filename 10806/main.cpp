#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <utility>
#include <deque>
#include <unordered_set>

#define NEXTID_ERROR 0xFFFFFFFFFFFFFFFF
uint64_t _nextid = 0;
uint64_t getUid() {
    if (_nextid != NEXTID_ERROR)
        _nextid++;
    return _nextid - 1;
}

template <typename DT> class Node;

template <typename DT>
class Connection {
private:
    Node<DT>* nodepair[2];
    uint64_t connid;

public:
    Connection(Node<DT>* pair1, Node<DT>* pair2) {
        nodepair[0] = pair1;
        nodepair[1] = pair2;
    }

    Node<DT>* getConnTarget(Node<DT>* dt) {
        return dt == nodepair[0] ? nodepair[1] : nodepair[0];
    }

    bool operator==(const Connection& conn) const {
        return (this->connid == conn.connid) && 
            ((nodepair[0] == conn.nodepair[0] && nodepair[1] == conn.nodepair[1]) || 
                (nodepair[0] == conn.nodepair[1] && nodepair[1] == conn.nodepair[0]));
    }
};

template <typename DT>
class Node {
private:
    std::vector< Connection<DT> > connlist;
    DT data;
    int oprdata;

public:
    Node(DT data) {
        this->data = data;
        this->oprdata = 0;
    }
    
    DT getData() {
        return data;
    }
    void setData(DT data) {
        this->data = data;
    }

    int getOprData() {
        return oprdata;
    }
    void setOprData(int oprdata) {
        this->oprdata = oprdata;
    }

    void addNodeConnection(Node* node, bool addother = true) {
        connlist.push_back(Connection<DT>(this, node));
        if (addother)
            node->addNodeConnection(this, false);
    }
    int removeNodeConnection(Node* node) {
        typename std::vector< Connection<DT> >::iterator it = connlist.begin();
        for (; it != connlist.end(); it++) {
            if ((*it).getConnTarget(this) == node) {
                connlist.erase(it);
                return 0;
            }
        }
        return 1;
    }

    std::vector<Node*> getConnectedNodeList() {
        std::vector<Node*> result;
        for (int i = 0; i < connlist.size(); i++) {
            result.push_back(connlist[i].getConnTarget(this));
        }
        return result;
    }
    int getConnectionCount() {
        return connlist.size();
    }

    bool isConnectedTo(Node* dest) {
        std::vector<Node*> treelist;
        getTreeNdoeList(&treelist, this);
        typename std::vector<Node*>::iterator result = std::find(treelist.begin(), treelist.end(), dest);
        return result != treelist.end();
    }

    static std::vector<Node*>* getTreeEndNodeList(std::vector<Node*>* result, Node* start) {
        for (int i = 0;; i++) {
            if (i >= result->size())
                break;
            if ((*result)[i]->getConnectionCount() > 1) {
                result->erase(result->begin() + i);
                i--;
            }
        }
        return result;
    }

    static std::vector<Node*>* getTreeNodeList(std::vector<Node*>* result, Node* start, int rec = 0) {
        result->push_back(start);
        start->setOprData(1);
        
        std::vector<Node*> list = start->getConnectedNodeList();
        for (int i = 0; i < list.size(); i++) {
            if (list[i]->getOprData() != 1) {
                getTreeNodeList(result, list[i], 1);
            }
        }
        if (!rec) {
            for (int i = 0; i < result->size(); i++) {
                (*result)[i]->setOprData(0);
            }
        }
        return result;
    }
};

int main() {
    int nodecnt, conncnt;
    scanf("%d %d", &nodecnt, &conncnt);
    std::vector<Node<int>*> nodelist;
    nodelist.reserve(nodecnt);
    for (int i = 0; i < nodecnt; i++) {
        nodelist.push_back(new Node<int>(i + 1));
    }

    // Connect each nodes
    for (int i = 0; i < conncnt; i++) {
        int nindex1, nindex2;
        scanf("%d %d", &nindex1, &nindex2);
        nodelist[nindex1 - 1]->addNodeConnection(nodelist[nindex2 - 1]);
    }

    // Check connection
    for (int i = 0; i < nodecnt; i++) {
        printf("!! node #%d is connected to -> ", nodelist[i]->getData());
        std::vector<Node<int>*> cnodelist = nodelist[i]->getConnectedNodeList();
        for (int j = 0; j < cnodelist.size(); j++) {
            printf("#%d ", cnodelist[j]->getData());
        }
        printf("\n");
    }

    // Separate node group
    std::unordered_set<size_t> uncheckednodelist;
    std::vector< std::vector< Node<int>* > > nodegrouplist;
    std::vector<Node<int>*> sagrouplist;
    for (int i = 0; i < nodelist.size(); i++)
        uncheckednodelist.insert((size_t)nodelist[i]);

    for (int i = 0; i < nodelist.size(); i++) {
        if (uncheckednodelist.find((size_t)nodelist[i]) == uncheckednodelist.end())
            continue;
        std::vector<Node<int>*> endnodelist;

        Node<int>::getTreeNodeList(&endnodelist, nodelist[i]);
        for (int i = 0; i < endnodelist.size(); i++)
            uncheckednodelist.erase((size_t)endnodelist[i]);
        Node<int>* tmp = endnodelist[0];
        Node<int>* tmp2 = endnodelist[1];
        int treesize = endnodelist.size();

        Node<int>::getTreeEndNodeList(&endnodelist, nodelist[i]);
        if (endnodelist.size() == 0) {
            endnodelist.push_back(tmp);
            endnodelist.push_back(tmp);
        } else if (endnodelist.size() == 1) {
            if (treesize != 1)
                endnodelist.push_back(tmp == endnodelist[0] ? tmp2 : tmp);
            else {
                sagrouplist.push_back(endnodelist[0]);
                continue;
            }
        }
        nodegrouplist.push_back(endnodelist);
    }

    for (int i = 0; i < nodegrouplist.size(); i++) {
        printf("End node of node group #%d: ", i);
        for (int j = 0; j < (nodegrouplist[i]).size(); j++) {
            printf("%d ", (nodegrouplist[i][j])->getData());
        }
        printf("\n");
    }

    printf("Standalone groups: ");
    for (int i = 0; i < sagrouplist.size(); i++) {
        printf("%d ", (sagrouplist[i])->getData());
    }
    printf("\n");

    std::vector< std::pair<int, int> > resultpair;

    if (sagrouplist.size() > 0) {
        resultpair.push_back(std::make_pair())
        for (int i = 0; i < sagrouplist.size() - 1; i++) {

        }
    }

    for (int i = 0; i < nodecnt; i++)
        delete nodelist[i];
    return 0;
}