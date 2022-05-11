#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>

#include "../code snippets/nodegraph.ccsn"

void getcandidatelist(std::map<Node<int>*, int>* clist, Node<int>* start, int mvcnt) {
    (*clist)[start] = mvcnt == 0;
    if (mvcnt == 0)
        return;

    for (int i = 0; i < start->getConnectionCount(); i++) {
        std::vector<Node<int>*> cnodelist = start->getConnectedNodeList();
        for (int j = 0; j < cnodelist.size(); j++) {
            getcandidatelist(clist, cnodelist[j], mvcnt - 1);
        }
    }
}

int main() {
    int nodecnt, linkcnt, startnode, movecnt;
    scanf("%d %d %d %d", &nodecnt, &linkcnt, &startnode, &movecnt);
    Node<int>** nodelist = (Node<int>**)malloc(sizeof(Node<int>*) * nodecnt);

    for (int i = 0; i < nodecnt; i++) {
        nodelist[i] = new Node<int>(i + 1);
    }

    for (int i = 0; i < linkcnt; i++) {
        int p1, p2;
        scanf("%d %d", &p1, &p2);
        nodelist[p1 - 1]->addNodeConnection(nodelist[p2 - 1]);
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

    std::map<Node<int>*, int> candidates;
    if (nodelist[startnode - 1]->getConnectionCount() == 0) {
        printf("-1\n");
        goto end;
    }

    getcandidatelist(&candidates, nodelist[startnode - 1], movecnt);
    for (std::map<Node<int>*, int>::iterator it = candidates.begin(); it != candidates.end(); it++) {
        if ((*it).second)
            printf("%d ", (*it).first->getData());
    }

end:
    for (int i = 0; i < nodecnt; i++) {
        delete nodelist[i];
    }
    free(nodelist);
}