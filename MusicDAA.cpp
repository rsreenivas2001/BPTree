#include <iostream>
#include <string>
#include <windows.h>
#include <climits>
#include <fstream>
#include <sstream>

using namespace std;
// global declaration of MAx
int MAX = 3;

//Song class
class Song
{
public:
    int index;
    string name;
    string artist_name;
    string album_name;
    string genre_name;
    string playlist_name1;
    string playlist_name2;
    string playlist_name3;
    LPCSTR url; // Youtube link of song track
};

// BP node
class Node
{
    bool IS_LEAF;
    int *key, size;
    Song **trackadd;
    Node **ptr;
    friend class BPTree;

public:
    Node();
};

// BP tree
class BPTree
{
    Node *root;
    void insertInternal(int, Song *, Node *, Node *);
    Node *findParent(Node *, Node *);

public:
    BPTree();
    Song *search(int, Song **);
    void insert(int, Song *);
    //void display(Node*);
    //Node* getRoot();
};

// Constructor of Node
Node::Node()
{
    key = new int[MAX];
    trackadd = new Song *[MAX];
    ptr = new Node *[MAX + 1];
}

// Initialise the BPTree Node
BPTree::BPTree()
{
    root = NULL;
}

// Function to implement the Insert
// Operation in B+ Tree
void BPTree::insert(int x, Song *s)
{
    // If root is null then return
    // newly created node
    if (root == NULL)
    {
        root = new Node;
        root->key[0] = x;
        root->trackadd[0] = s;
        root->IS_LEAF = true;
        root->size = 1;
    }

    // Traverse the B+ Tree
    else
    {
        Node *cursor = root;
        Node *parent;

        // Till cursor reaches the
        // leaf node
        while (cursor->IS_LEAF == false)
        {

            parent = cursor;

            for (int i = 0; i < cursor->size; i++)
            {
                // If found the position
                // where we have to insert
                // node
                if (x < cursor->key[i])
                {
                    cursor = cursor->ptr[i];
                    break;
                }

                // If reaches the end
                if (i == cursor->size - 1)
                {
                    cursor = cursor->ptr[i + 1];
                    break;
                }
            }
        }

        if (cursor->size < MAX)
        {
            int i = 0;
            while (x > cursor->key[i] && i < cursor->size)
            {
                i++;
            }

            for (int j = cursor->size; j > i; j--)
            {
                cursor->key[j] = cursor->key[j - 1];
                cursor->trackadd[j] = cursor->trackadd[j - 1];
            }

            cursor->key[i] = x;
            cursor->trackadd[i] = s;
            cursor->size++;

            cursor->ptr[cursor->size] = cursor->ptr[cursor->size - 1];
            cursor->ptr[cursor->size - 1] = NULL;
        }

        else
        {
            // Create a newLeaf node
            Node *newLeaf = new Node;

            int virtualNode[MAX + 1];
            Song *virtualAdd[MAX + 1];

            // Update cursor to virtual
            // node created
            for (int i = 0; i < MAX; i++)
            {
                virtualNode[i] = cursor->key[i];
                virtualAdd[i] = cursor->trackadd[i];
            }
            int i = 0, j;

            // Traverse to find where the new
            // node is to be inserted
            while (x > virtualNode[i] && i < MAX)
            {
                i++;
            }

            for (int j = MAX + 1; j > i; j--)
            {
                virtualNode[j] = virtualNode[j - 1];
                virtualAdd[j] = virtualAdd[j - 1];
            }

            virtualNode[i] = x;
            virtualAdd[i] = s;
            newLeaf->IS_LEAF = true;

            cursor->size = (MAX + 1) / 2;
            newLeaf->size = MAX + 1 - (MAX + 1) / 2;

            cursor->ptr[cursor->size] = newLeaf;

            newLeaf->ptr[newLeaf->size] = cursor->ptr[MAX];

            cursor->ptr[MAX] = NULL;

            for (i = 0; i < cursor->size; i++)
            {
                cursor->key[i] = virtualNode[i];
                cursor->trackadd[i] = virtualAdd[i];
            }

            for (i = 0, j = cursor->size; i < newLeaf->size; i++, j++)
            {
                newLeaf->key[i] = virtualNode[j];
                newLeaf->trackadd[i] = virtualAdd[j];
            }

            if (cursor == root)
            {
                Node *newRoot = new Node;

                newRoot->key[0] = newLeaf->key[0];
                newRoot->trackadd[0] = newLeaf->trackadd[0];
                newRoot->ptr[0] = cursor;
                newRoot->ptr[1] = newLeaf;
                newRoot->IS_LEAF = false;
                newRoot->size = 1;
                root = newRoot;
            }
            else
            {
                insertInternal(newLeaf->key[0], newLeaf->trackadd[0], parent, newLeaf);
            }
        }
    }
}

// Function to implement the Insert
// Internal Operation in B+ Tree
void BPTree::insertInternal(int x, Song *s, Node *cursor, Node *child)
{
    if (cursor->size < MAX)
    {
        int i = 0;

        while (x > cursor->key[i] && i < cursor->size)
        {
            i++;
        }

        // Traverse the cursor node
        // and update the current key
        // to its previous node key
        for (int j = cursor->size; j > i; j--)
        {
            cursor->key[j] = cursor->key[j - 1];
            cursor->trackadd[j] = cursor->trackadd[j - 1];
        }

        // Traverse the cursor node
        // and update the current ptr
        // to its previous node ptr
        for (int j = cursor->size + 1; j > i + 1; j--)
        {
            cursor->ptr[j] = cursor->ptr[j - 1];
        }

        cursor->key[i] = x;
        cursor->trackadd[i] = s;
        cursor->size++;
        cursor->ptr[i + 1] = child;
    }
    // For overflow, break the node
    else
    {
        // Create a newLeaf node
        Node *newInternal = new Node;
        int virtualKey[MAX + 1];
        Song *virtualAdr[MAX + 1];
        Node *virtualPtr[MAX + 2];

        // Update cursor to virtual
        // node created
        for (int i = 0; i < MAX; i++)
        {
            virtualKey[i] = cursor->key[i];
            virtualAdr[i] = cursor->trackadd[i];
        }

        for (int i = 0; i < MAX + 1; i++)
        {
            virtualPtr[i] = cursor->ptr[i];
        }

        int i = 0, j;

        // Traverse to find where the new
        // node is to be inserted
        while (x > virtualKey[i] && i < MAX)
        {
            i++;
        }

        // Update the current virtual
        // Node to its previous
        for (int j = MAX + 1; j > i; j--)
        {
            virtualKey[j] = virtualKey[j - 1];
            virtualAdr[j] = virtualAdr[j - 1];
        }

        virtualKey[i] = x;
        virtualAdr[i] = s;

        for (int j = MAX + 2; j > i + 1; j--)
        {
            virtualPtr[j] = virtualPtr[j - 1];
        }

        virtualPtr[i + 1] = child;
        newInternal->IS_LEAF = false;

        cursor->size = (MAX + 1) / 2;

        newInternal->size = MAX - (MAX + 1) / 2;

        // Update the current virtual
        // Node's key to its previous
        for (i = 0, j = cursor->size + 1; i < newInternal->size; i++, j++)
        {
            newInternal->key[i] = virtualKey[j];
            newInternal->trackadd[i] = virtualAdr[j];
        }

        // Update the newLeaf key to
        // virtual Node
        for (i = 0, j = cursor->size + 1; i < newInternal->size + 1; i++, j++)
        {
            newInternal->ptr[i] = virtualPtr[j];
        }

        // If cursor is the root node
        if (cursor == root)
        {
            // Create a new Node
            Node *newRoot = new Node;

            // Update rest field of
            // B+ Tree Node
            newRoot->key[0] = cursor->key[cursor->size];
            newRoot->trackadd[0] = cursor->trackadd[cursor->size];

            newRoot->ptr[0] = cursor;
            newRoot->ptr[1] = newInternal;
            newRoot->IS_LEAF = false;
            newRoot->size = 1;
            root = newRoot;
        }

        else
        {
            // Recursive Call for
            // insert in internal
            insertInternal(cursor->key[cursor->size], cursor->trackadd[cursor->size], findParent(root, cursor), newInternal);
        }
    }
}

// Function to find the parent node
Node *BPTree::findParent(Node *cursor, Node *child)
{
    Node *parent;

    // If cursor reaches the end of Tree
    if (cursor->IS_LEAF || (cursor->ptr[0])->IS_LEAF)
    {
        return NULL;
    }

    // Traverse the current node with
    // all its child
    for (int i = 0; i < cursor->size + 1; i++)
    {
        // Update the parent for the
        // child Node
        if (cursor->ptr[i] == child)
        {
            parent = cursor;
            return parent;
        }

        // Else recursively traverse to
        // find child node
        else
        {
            parent = findParent(cursor->ptr[i], child);

            // If parent is found, then
            // return that parent node
            if (parent != NULL)
                return parent;
        }
    }

    // Return parent node
    return parent;
}

// Function to find any element
// in B+ Tree
Song *BPTree::search(int x, Song **a)
{

    // If tree is empty
    if (root == NULL)
    {
        cout << "Tree is empty\n";
    }

    // Traverse to find the value
    else
    {
        Node *cursor = root;
        Node *pointer;

        // Till we reach leaf node
        while (cursor->IS_LEAF == false)
        {
            for (int i = 0; i < cursor->size; i++)
            {
                // If the element to be
                // found is not present
                if (x < cursor->key[i])
                {
                    cursor = cursor->ptr[i];
                    break;
                }

                // If reaches end of the
                // cursor node
                if (i == cursor->size - 1)
                {
                    cursor = cursor->ptr[i + 1];
                    break;
                }
            }
        }

        // Traverse the cursor and find
        // the node with value x
        int pq, am, sl;
        for (int i = 0; i < cursor->size; i++)
        {
            // If found then return
            if (cursor->key[i] == x)
            {
                sl = i;
                pq = i + 1;
                pointer = cursor;
                break;
            }
        }
        if (cursor->ptr[pq] != NULL)
        {
            cursor = cursor->ptr[pq + 1];
            pq = 0;
            while (cursor->ptr[pq] == NULL && cursor->key[pq] != 0)
            {
                a[am] = cursor->trackadd[pq];
                am++;
                pq++;
                if (cursor->ptr[pq] != NULL)
                {
                    cursor = cursor->ptr[pq];
                    pq = 0;
                }
            }
        }
        else
        {
            while (cursor->ptr[pq] == NULL && cursor->key[pq] != 0)
            {
                a[am] = cursor->trackadd[pq];
                am++;
                pq++;
                if (cursor->ptr[pq] != NULL)
                {
                    cursor = cursor->ptr[pq];
                    pq = 0;
                }
            }
        }
        return pointer->trackadd[sl];
        return 0;
    }
}

//global declaration of array of Song
Song Tracks[113];

int main()
{
    LPCSTR verb = "open";
    BPTree LatestTamil, HeartBreakers, RomanticAcoustics, IniyaIravu, PartyTonight;
    BPTree AR, GV, BD, LJ, SS, HHT, DH, YSR, SN, DV, DI, HJ, VM, SCS, ARR;
    BPTree Party, Melody, Love, Mood, Rap, Folk;
    int opt, opt1, opt2, opt3, opt4;
    int ind[30] = {0};
    int trv, count, i, f, nxt;
    char ch;
    Song *find = NULL;
    Song *tra[50] = {0};

    //assigning Song object attributes
    Tracks[0].index = 100;
    Tracks[0].name = "VAATHI COMING";
    Tracks[0].artist_name = "ANIRUDH RAVICHANDER";
    Tracks[0].album_name = "MASTER";
    Tracks[0].genre_name = "PARTY";
    Tracks[0].playlist_name1 = "LATEST TAMIL";
    Tracks[0].playlist_name2 = "PARTY TONIGHT";
    Tracks[0].url = "https://www.youtube.com/watch?v=vxzfsBDx590";

    Tracks[1].index = 101;
    Tracks[1].name = "ANDHA KANNA PAATHAKA";
    Tracks[1].artist_name = "ANIRUDH RAVICHANDER";
    Tracks[1].album_name = "MASTER";
    Tracks[1].genre_name = "MELODY";
    Tracks[1].playlist_name1 = "LATEST TAMIL";
    Tracks[1].url = "https://www.youtube.com/watch?v=3hVc3M1IEe0";

    Tracks[2].index = 102;
    Tracks[2].name = "VEYYON SILLI";
    Tracks[2].artist_name = "G.V.PRAKASH KUMAR";
    Tracks[2].album_name = "SOORARAI POTTRU";
    Tracks[2].genre_name = "LOVE";
    Tracks[2].playlist_name1 = "LATEST TAMIL";
    Tracks[2].url = "https://www.youtube.com/watch?v=0f_ho4Wem0w";

    Tracks[3].index = 103;
    Tracks[3].name = "KUTTI STORY";
    Tracks[3].artist_name = "ANIRUDH RAVICHANDER";
    Tracks[3].album_name = "MASTER";
    Tracks[3].genre_name = "MOOD";
    Tracks[3].playlist_name1 = "LATEST TAMIL";
    Tracks[3].url = "https://www.youtube.com/watch?v=gjnrtCKZqYg";

    Tracks[4].index = 104;
    Tracks[4].name = "SIRIKKALAM PARAKKALAM";
    Tracks[4].artist_name = "BENNY DAYAL";
    Tracks[4].album_name = "KANNUM KANNUM KOLLAIYADITHAL";
    Tracks[4].genre_name = "PARTY";
    Tracks[4].playlist_name1 = "LATEST TAMIL";
    Tracks[4].url = "https://www.youtube.com/watch?v=vlYv7Ri-GQU";

    Tracks[5].index = 105;
    Tracks[5].name = "YELO PULLELO";
    Tracks[5].artist_name = "ANIRUDH RAVICHANDER";
    Tracks[5].album_name = "KANNUM KANNUM KOLLAIYADITHAL";
    Tracks[5].genre_name = "PARTY";
    Tracks[5].playlist_name1 = "LATEST TAMIL";
    Tracks[5].url = "https://www.youtube.com/watch?v=nfH0pa0VSBI";

    Tracks[6].index = 106;
    Tracks[6].name = "VAATHI RAID";
    Tracks[6].artist_name = "ANIRUDH RAVICHANDER";
    Tracks[6].album_name = "MASTER";
    Tracks[6].genre_name = "RAP";
    Tracks[6].playlist_name1 = "LATEST TAMIL";
    Tracks[6].url = "https://www.youtube.com/watch?v=eHoIUNY-bG4";

    Tracks[7].index = 107;
    Tracks[7].name = "MANNURUNDA";
    Tracks[7].artist_name = "G.V.PRAKASH KUMAR";
    Tracks[7].album_name = "SOORARAI POTTRU";
    Tracks[7].genre_name = "FOLK";
    Tracks[7].playlist_name1 = "LATEST TAMIL";
    Tracks[7].url = "https://www.youtube.com/watch?v=KDlkS6l2ZTU";

    Tracks[8].index = 108;
    Tracks[8].name = "KADHAIPOMA";
    Tracks[8].artist_name = "LEON JAMES";
    Tracks[8].album_name = "OH MY KADAVULE";
    Tracks[8].genre_name = "MELODY";
    Tracks[8].playlist_name1 = "LATEST TAMIL";
    Tracks[8].url = "https://www.youtube.com/watch?v=DScFlfN9vDk";

    Tracks[9].index = 109;
    Tracks[9].name = "KAADHAL THEEVEY";
    Tracks[9].artist_name = "SID SRIRAM";
    Tracks[9].album_name = "DHARALA PRABHU";
    Tracks[9].genre_name = "MELODY";
    Tracks[9].playlist_name1 = "LATEST TAMIL";
    Tracks[9].url = "https://www.youtube.com/watch?v=NGkEwWewgmY";

    Tracks[10].index = 110;
    Tracks[10].name = "BREAKUP SONG";
    Tracks[10].artist_name = "HIP HOP THAMIZHA";
    Tracks[10].album_name = "NAAN SIRITHAAL";
    Tracks[10].genre_name = "PARTY";
    Tracks[10].playlist_name1 = "LATEST TAMIL";
    Tracks[10].playlist_name2 = "HEART BREAKERS";
    Tracks[10].playlist_name3 = "PARTY TONIGHT";
    Tracks[10].url = "https://www.youtube.com/watch?v=lxROTQJEB58";

    Tracks[11].index = 111;
    Tracks[11].name = "HAIYO HAIYO";
    Tracks[11].artist_name = "LEON JAMES";
    Tracks[11].album_name = "OH MY KADAVULE";
    Tracks[11].genre_name = "LOVE";
    Tracks[11].playlist_name1 = "LATEST TAMIL";
    Tracks[11].url = "https://www.youtube.com/watch?v=lJXDFmqr564";

    Tracks[12].index = 112;
    Tracks[12].name = "AJUKKU GUMUKKU";
    Tracks[12].artist_name = "HIP HOP THAMIZHA";
    Tracks[12].album_name = "NAAN SIRITHAAL";
    Tracks[12].genre_name = "FOLK";
    Tracks[12].playlist_name1 = "LATEST TAMIL";
    Tracks[12].url = "https://www.youtube.com/watch?v=ji55jouN_8k";

    Tracks[13].index = 113;
    Tracks[13].name = "CHILL BRO";
    Tracks[13].artist_name = "DHANUSH";
    Tracks[13].album_name = "PATTAS";
    Tracks[13].genre_name = "PARTY";
    Tracks[13].playlist_name1 = "LATEST TAMIL";
    Tracks[13].playlist_name2 = "PARTY TONIGHT";
    Tracks[14].url = "https://www.youtube.com/watch?v=pHxz8l1iWU4";

    Tracks[14].index = 114;
    Tracks[14].name = "NAAN SIRICHA";
    Tracks[14].artist_name = "HIP HOP THAMIZHA";
    Tracks[14].album_name = "NAAN SIRITHAAL";
    Tracks[14].genre_name = "PARTY";
    Tracks[14].playlist_name1 = "LATEST TAMIL";
    Tracks[14].url = "https://www.youtube.com/watch?v=Ckwj8Xsil88";

    Tracks[15].index = 115;
    Tracks[15].name = "JIGIDI KILLADI";
    Tracks[15].artist_name = "ANIRUDH RAVICHANDER";
    Tracks[15].album_name = "PATTAS";
    Tracks[15].genre_name = "LOVE";
    Tracks[15].playlist_name1 = "LATEST TAMIL";
    Tracks[15].url = "https://www.youtube.com/watch?v=v7RwLCdx-AI";

    Tracks[16].index = 116;
    Tracks[16].name = "OVERA FEEL PANNUREN";
    Tracks[16].artist_name = "YUVAN SHANKAR RAJA";
    Tracks[16].album_name = "HERO";
    Tracks[16].genre_name = "LOVE";
    Tracks[16].playlist_name1 = "LATEST TAMIL";
    Tracks[16].url = "https://www.youtube.com/watch?v=kBHstSYCgew";

    Tracks[17].index = 117;
    Tracks[17].name = "DHOM DHOM";
    Tracks[17].artist_name = "HIP HOP THAMIZHA";
    Tracks[17].album_name = "NAAN SIRITHAAL";
    Tracks[17].genre_name = "MELODY";
    Tracks[17].playlist_name1 = "LATEST TAMIL";
    Tracks[17].url = "https://www.youtube.com/watch?v=29FUG72LVFE";

    Tracks[18].index = 118;
    Tracks[18].name = "YEAN ENNAI PIRINDHAAI";
    Tracks[18].artist_name = "SID SRIRAM";
    Tracks[18].album_name = "ADITHYA VARMA";
    Tracks[18].genre_name = "MELODY";
    Tracks[18].playlist_name1 = "LATEST TAMIL";
    Tracks[18].playlist_name2 = "HEART BREAKERS";
    Tracks[18].url = "https://www.youtube.com/watch?v=9pWrJM5nkl4";

    Tracks[19].index = 119;
    Tracks[19].name = "UNNA NENACHU";
    Tracks[19].artist_name = "SID SRIRAM";
    Tracks[19].album_name = "PSYCHO";
    Tracks[19].genre_name = "MELODY";
    Tracks[19].playlist_name1 = "LATEST TAMIL";
    Tracks[19].playlist_name2 = "HEART BREAKERS";
    Tracks[19].playlist_name3 = "ROMANTIC ACOUSTICS";
    Tracks[19].url = "https://www.youtube.com/watch?v=jFWsj_QT0G8";

    Tracks[20].index = 120;
    Tracks[20].name = "MALTO KITHAPULEH";
    Tracks[20].artist_name = "YUVAN SHANKAR RAJA";
    Tracks[20].album_name = "HERO";
    Tracks[20].genre_name = "PARTY";
    Tracks[20].playlist_name1 = "LATEST TAMIL";
    Tracks[20].url = "https://www.youtube.com/watch?v=NHzwno5Y2XA";

    Tracks[21].index = 121;
    Tracks[21].name = "QUIT PANNUDA";
    Tracks[21].artist_name = "ANIRUDH RAVICHANDER";
    Tracks[21].album_name = "MASTER";
    Tracks[21].genre_name = "MELODY";
    Tracks[21].playlist_name1 = "LATEST TAMIL";
    Tracks[21].url = "https://www.youtube.com/watch?v=fccXKFiXEGU";

    Tracks[22].index = 122;
    Tracks[22].name = "POLAKATUM PARA PARA";
    Tracks[22].artist_name = "SANTHOSH NARAYANAN";
    Tracks[22].album_name = "MASTER";
    Tracks[22].genre_name = "FOLK";
    Tracks[22].playlist_name1 = "LATEST TAMIL";
    Tracks[22].url = "https://www.youtube.com/watch?v=dZN4TD9Ane0";

    Tracks[23].index = 123;
    Tracks[23].name = "EDHARKADI";
    Tracks[23].artist_name = "DHRUV VIKRAM";
    Tracks[23].album_name = "ADITHYA VARMA";
    Tracks[23].genre_name = "LOVE";
    Tracks[23].playlist_name1 = "HEART BREAKERS";
    Tracks[23].url = "https://www.youtube.com/watch?v=Y1JCAXAxoMg";

    Tracks[24].index = 124;
    Tracks[24].name = "IMAYE IMAYE";
    Tracks[24].artist_name = "G.V.PRAKASH KUMAR";
    Tracks[24].album_name = "RAJA RANI";
    Tracks[24].genre_name = "MELODY";
    Tracks[24].playlist_name1 = "HEART BREAKERS";
    Tracks[24].url = "https://www.youtube.com/watch?v=d38xWWg62LY";

    Tracks[25].index = 125;
    Tracks[25].name = "MARANDHAYE";
    Tracks[25].artist_name = "D.IMMAN";
    Tracks[25].album_name = "TEDDY";
    Tracks[25].genre_name = "MELODY";
    Tracks[25].playlist_name1 = "HEART BREAKERS";
    Tracks[25].url = "https://www.youtube.com/watch?v=gIDG3cd_I7I";

    Tracks[26].index = 126;
    Tracks[26].name = "POGADHE";
    Tracks[26].artist_name = "YUVAN SHANKAR RAJA";
    Tracks[26].album_name = "DEEPAVALI";
    Tracks[26].genre_name = "MELODY";
    Tracks[26].playlist_name1 = "HEART BREAKERS";
    Tracks[26].url = "https://www.youtube.com/watch?v=ujV-0AT60pU";

    Tracks[27].index = 127;
    Tracks[27].name = "AVA ENNA";
    Tracks[27].artist_name = "HARRIS JAYARAJ";
    Tracks[27].album_name = "VAARANAM AAYIRAM";
    Tracks[27].genre_name = "FOLK";
    Tracks[27].playlist_name1 = "HEART BREAKERS";
    Tracks[27].url = "https://www.youtube.com/watch?v=5yjy7djTUDc";

    Tracks[28].index = 128;
    Tracks[28].name = "MOONGIL THOTTAM";
    Tracks[28].artist_name = "A.R.RAHMAN";
    Tracks[28].album_name = "KADAL";
    Tracks[28].genre_name = "MELODY";
    Tracks[28].playlist_name1 = "HEART BREAKERS";
    Tracks[28].playlist_name2 = "ROMANTIC ACOUSTICS";
    Tracks[28].playlist_name3 = "INIYA IRAVU";
    Tracks[28].url = "https://www.youtube.com/watch?v=EQ783EHQkng";

    Tracks[29].index = 129;
    Tracks[29].name = "VAADI PULLA VAADI";
    Tracks[29].artist_name = "HIP HOP THAMIZHA";
    Tracks[29].album_name = "MEESAYA MURUKKU";
    Tracks[29].genre_name = "LOVE";
    Tracks[29].playlist_name1 = "HEART BREAKERS";
    Tracks[29].url = "https://www.youtube.com/watch?v=7mWd8fOG7qI";

    Tracks[30].index = 130;
    Tracks[30].name = "SERAMAL PONAL";
    Tracks[30].artist_name = "VIVEK-MERVIN";
    Tracks[30].album_name = "GULEBAGAVALI";
    Tracks[30].genre_name = "MELODY";
    Tracks[30].playlist_name1 = "HEART BREAKERS";
    Tracks[30].playlist_name2 = "INIYA IRAVU";
    Tracks[30].url = "https://www.youtube.com/watch?v=URgqLY3Z7PQ";

    Tracks[31].index = 131;
    Tracks[31].name = "OH PENNE";
    Tracks[31].artist_name = "ANIRUDH RAVICHANDER";
    Tracks[31].album_name = "VANAKKAM CHENNAI";
    Tracks[31].genre_name = "MELODY";
    Tracks[31].playlist_name1 = "HEART BREAKERS";
    Tracks[31].playlist_name2 = "INIYA IRAVU";
    Tracks[31].url = "https://www.youtube.com/watch?v=C7MAqIcM-Sg";

    Tracks[32].index = 132;
    Tracks[32].name = "MEGAMO AVAL";
    Tracks[32].artist_name = "SANTHOSH NARAYANAN";
    Tracks[32].album_name = "MEYAADHA MAAN";
    Tracks[32].genre_name = "MELODY";
    Tracks[32].playlist_name1 = "HEART BREAKERS";
    Tracks[32].url = "https://www.youtube.com/watch?v=mVubYBRajfw";

    Tracks[33].index = 133;
    Tracks[33].name = "YEDHO ONDRU ENNAI";
    Tracks[33].artist_name = "YUVAN SHANKAR RAJA";
    Tracks[33].album_name = "PAIYA";
    Tracks[33].genre_name = "LOVE";
    Tracks[33].playlist_name1 = "HEART BREAKERS";
    Tracks[33].url = "https://www.youtube.com/watch?v=UeYP7909Ovg";

    Tracks[34].index = 134;
    Tracks[34].name = "DHIMU DHIMU";
    Tracks[34].artist_name = "HARRIS JAYARAJ";
    Tracks[34].album_name = "ENGEYUM KADHAL";
    Tracks[34].genre_name = "MELODY";
    Tracks[34].playlist_name1 = "HEART BREAKERS";
    Tracks[34].url = "https://www.youtube.com/watch?v=QoK8x_2C4go";

    Tracks[35].index = 135;
    Tracks[35].name = "PO URAVE";
    Tracks[35].artist_name = "SID SRIRAM";
    Tracks[35].album_name = "KAATRIN MOZHI";
    Tracks[35].genre_name = "MOOD";
    Tracks[35].playlist_name1 = "HEART BREAKERS";
    Tracks[35].url = "https://www.youtube.com/watch?v=JdVPh0vu2zI";

    Tracks[36].index = 136;
    Tracks[36].name = "MANNIPAAYA";
    Tracks[36].artist_name = "A.R.RAHMAN";
    Tracks[36].album_name = "VINNAI THAANDI VARUVAYAA";
    Tracks[36].genre_name = "MELODY";
    Tracks[36].playlist_name1 = "HEART BREAKERS";
    Tracks[36].url = "https://www.youtube.com/watch?v=EjUP08N89mI";

    Tracks[37].index = 137;
    Tracks[37].name = "KADHAL ORU AAGAYAM";
    Tracks[37].artist_name = "HIP HOP THAMIZHA";
    Tracks[37].album_name = "IMAIKKA NODIGAL";
    Tracks[37].genre_name = "MELODY";
    Tracks[37].playlist_name1 = "HEART BREAKERS";
    Tracks[37].url = "https://www.youtube.com/watch?v=kmhrT7fPYO4";

    Tracks[38].index = 138;
    Tracks[38].name = "PO NEE PO";
    Tracks[38].artist_name = "ANIRUDH RAVICHANDER";
    Tracks[38].album_name = "THREE";
    Tracks[38].genre_name = "LOVE";
    Tracks[38].playlist_name1 = "HEART BREAKERS";
    Tracks[38].url = "https://www.youtube.com/watch?v=DnyA_qEbTpw";

    Tracks[39].index = 139;
    Tracks[39].name = "MUNNAL KADHALI";
    Tracks[39].artist_name = "D.IMMAN";
    Tracks[39].album_name = "MIRUTHAN";
    Tracks[39].genre_name = "MOOD";
    Tracks[39].playlist_name1 = "HEART BREAKERS";
    Tracks[39].url = "https://www.youtube.com/watch?v=q4u4zIbhkdI";

    Tracks[40].index = 140;
    Tracks[40].name = "KAADHAL ENDRAL";
    Tracks[40].artist_name = "YUVAN SHANKAR RAJA";
    Tracks[40].album_name = "GOA";
    Tracks[40].genre_name = "LOVE";
    Tracks[40].playlist_name1 = "HEART BREAKERS";
    Tracks[40].url = "https://www.youtube.com/watch?v=dfGpFJW9GHY";

    Tracks[41].index = 141;
    Tracks[41].name = "THODU VAANAM";
    Tracks[41].artist_name = "HARRIS JAYARAJ";
    Tracks[41].album_name = "ANEGAN";
    Tracks[41].genre_name = "MOOD";
    Tracks[41].playlist_name1 = "HEART BREAKERS";
    Tracks[41].url = "https://www.youtube.com/watch?v=vSYI6ZrkE80";

    Tracks[42].index = 142;
    Tracks[42].name = "USURE POGUDHEY";
    Tracks[42].artist_name = "A.R.RAHMAN";
    Tracks[42].album_name = "RAAVANAN";
    Tracks[42].genre_name = "MELODY";
    Tracks[42].playlist_name1 = "HEART BREAKERS";
    Tracks[42].url = "https://www.youtube.com/watch?v=yCKO5KUDcVs";

    Tracks[43].index = 143;
    Tracks[43].name = "THOOVANAM";
    Tracks[43].artist_name = "D.IMMAN";
    Tracks[43].album_name = "ROMEO JULIET";
    Tracks[43].genre_name = "LOVE";
    Tracks[43].playlist_name1 = "HEART BREAKERS";
    Tracks[43].url = "https://www.youtube.com/watch?v=K9jQm0FZZ98";

    Tracks[44].index = 144;
    Tracks[44].name = "KADHAL VALARTHEN";
    Tracks[44].artist_name = "YUVAN SHANKAR RAJA";
    Tracks[44].album_name = "MANMADHAN";
    Tracks[44].genre_name = "MOOD";
    Tracks[44].playlist_name1 = "HEART BREAKERS";
    Tracks[44].url = "https://www.youtube.com/watch?v=ALDVhVPnjus";

    Tracks[45].index = 145;
    Tracks[45].name = "NEE NENACHA";
    Tracks[45].artist_name = "SID SRIRAM";
    Tracks[45].album_name = "MR.LOCAL";
    Tracks[45].genre_name = "MOOD";
    Tracks[45].playlist_name1 = "HEART BREAKERS";
    Tracks[45].url = "https://www.youtube.com/watch?v=HUwEXHPEgdM";

    Tracks[46].index = 146;
    Tracks[46].name = "AAROMALE";
    Tracks[46].artist_name = "A.R.RAHMAN";
    Tracks[46].album_name = "VINNAI THAANDI VARUVAAYA";
    Tracks[46].genre_name = "MOOD";
    Tracks[46].playlist_name1 = "HEART BREAKERS";
    Tracks[46].url = "https://www.youtube.com/watch?v=q7OUFE3dw6E";

    Tracks[47].index = 147;
    Tracks[47].name = "ENNODU NEE IRUNTHAL";
    Tracks[47].artist_name = "A.R.RAHMAN";
    Tracks[47].album_name = "I";
    Tracks[47].genre_name = "MELODY";
    Tracks[47].playlist_name1 = "HEART BREAKERS";
    Tracks[47].playlist_name2 = "ROMANTIC ACOUSTICS";
    Tracks[47].url = "https://www.youtube.com/watch?v=EhhiY11Z9-U";

    Tracks[48].index = 148;
    Tracks[48].name = "DAAVUYA";
    Tracks[48].artist_name = "SANTHOSH NARAYANAN";
    Tracks[48].album_name = "REMO";
    Tracks[48].genre_name = "PARTY";
    Tracks[48].playlist_name1 = "HEART BREAKERS";
    Tracks[48].playlist_name2 = "PARTY TONIGHT";
    Tracks[48].url = "https://www.youtube.com/watch?v=GRKyx31fqjE";

    Tracks[49].index = 149;
    Tracks[49].name = "VENAAM MACHAN";
    Tracks[49].artist_name = "HARRIS JAYARAJ";
    Tracks[49].album_name = "OK OK";
    Tracks[49].genre_name = "FOLK";
    Tracks[49].playlist_name1 = "HEART BREAKERS";
    Tracks[49].url = "https://www.youtube.com/watch?v=Q_RiJmvmcyQ";

    Tracks[50].index = 150;
    Tracks[50].name = "VENMEGAM";
    Tracks[50].artist_name = "YUVAN SHANKAR RAJA";
    Tracks[50].album_name = "YAARADI NEE MOHINI";
    Tracks[50].genre_name = "MELODY";
    Tracks[50].playlist_name1 = "HEART BREAKERS";
    Tracks[50].url = "https://www.youtube.com/watch?v=JzTNs0gY_ZU";

    Tracks[51].index = 151;
    Tracks[51].name = "ADIYAE IVALEY";
    Tracks[51].artist_name = "D.IMMAN";
    Tracks[51].album_name = "ROMEO JULIET";
    Tracks[51].genre_name = "FOLK";
    Tracks[51].playlist_name1 = "HEART BREAKERS";
    Tracks[51].playlist_name2 = "PARTY TONIGHT";
    Tracks[51].url = "https://www.youtube.com/watch?v=E55QqxWUYk8";

    Tracks[52].index = 152;
    Tracks[52].name = "WHY THIS KOLAVERI DI";
    Tracks[52].artist_name = "DHANUSH";
    Tracks[52].album_name = "THREE";
    Tracks[52].genre_name = "PARTY";
    Tracks[52].playlist_name1 = "HEART BREAKERS";
    Tracks[52].url = "https://www.youtube.com/watch?v=YR12Z8f1Dh8";

    Tracks[53].index = 153;
    Tracks[53].name = "NENJUKKUL PEIDHIDUM";
    Tracks[53].artist_name = "HARRIS JAYARAJ";
    Tracks[53].album_name = "VAARANAM AAYIRAM";
    Tracks[53].genre_name = "MELODY";
    Tracks[53].playlist_name1 = "ROMANTIC ACOUSTICS";
    Tracks[53].playlist_name2 = "INIYA IRAVU";
    Tracks[53].url = "https://www.youtube.com/watch?v=FzLpP8VBC6E";

    Tracks[54].index = 154;
    Tracks[54].name = "SIRIKKADHEY";
    Tracks[54].artist_name = "ANIRUDH RAVICHANDER";
    Tracks[54].album_name = "REMO";
    Tracks[54].genre_name = "MELODY";
    Tracks[54].playlist_name1 = "ROMANTIC ACOUSTICS";
    Tracks[54].url = "https://www.youtube.com/watch?v=iiVANEoXeLY";

    Tracks[55].index = 155;
    Tracks[55].name = "ENGEYUM KADHAL";
    Tracks[55].artist_name = "HARRIS JAYARAJ";
    Tracks[55].album_name = "ENGEYUM KADHAL";
    Tracks[55].genre_name = "MELODY";
    Tracks[55].playlist_name1 = "ROMANTIC ACOUSTICS";
    Tracks[55].url = "https://www.youtube.com/watch?v=OH3_Jna80Uk";

    Tracks[56].index = 156;
    Tracks[56].name = "UNAKAGA";
    Tracks[56].artist_name = "A.R.RAHMAN";
    Tracks[56].album_name = "BIGIL";
    Tracks[56].genre_name = "LOVE";
    Tracks[56].playlist_name1 = "ROMANTIC ACOUSTICS";
    Tracks[56].playlist_name2 = "INIYA IRAVU";
    Tracks[56].url = "https://www.youtube.com/watch?v=IdDaf8Rr33E";

    Tracks[57].index = 157;
    Tracks[57].name = "NEW YORK";
    Tracks[57].artist_name = "A.R.RAHMAN";
    Tracks[57].album_name = "SILLUNU ORU KADHAL";
    Tracks[57].genre_name = "MELODY";
    Tracks[57].playlist_name1 = "ROMANTIC ACOUSTICS";
    Tracks[57].url = "https://www.youtube.com/watch?v=OjU54VhRFbU";

    Tracks[58].index = 158;
    Tracks[58].name = "OSAKA OSAKA";
    Tracks[58].artist_name = "ANIRUDH RAVICHANDER";
    Tracks[58].album_name = "VANAKKAM CHENNAI";
    Tracks[58].genre_name = "LOVE";
    Tracks[58].playlist_name1 = "ROMANTIC ACOUSTICS";
    Tracks[58].url = "https://www.youtube.com/watch?v=Ml5smnK5Taw";

    Tracks[59].index = 159;
    Tracks[59].name = "MARUVAARTHAI";
    Tracks[59].artist_name = "SID SRIRAM";
    Tracks[59].album_name = "ENAI NOKKI PAAYUM THOTA";
    Tracks[59].genre_name = "LOVE";
    Tracks[59].playlist_name1 = "ROMANTIC ACOUSTICS";
    Tracks[59].playlist_name2 = "INIYA IRAVU";
    Tracks[59].url = "https://www.youtube.com/watch?v=U3lyojCm6jA";

    Tracks[60].index = 160;
    Tracks[60].name = "ANBE ANBE";
    Tracks[60].artist_name = "G.V.PRAKASH KUMAR";
    Tracks[60].album_name = "DARLING";
    Tracks[60].genre_name = "LOVE";
    Tracks[60].playlist_name1 = "ROMANTIC ACOUSTICS";
    Tracks[60].url = "https://www.youtube.com/watch?v=YR4fS1segho";

    Tracks[61].index = 161;
    Tracks[61].name = "UN VIZHIGALIL";
    Tracks[61].artist_name = "ANIRUDH RAVICHANDER";
    Tracks[61].album_name = "MAAN KARATE";
    Tracks[61].genre_name = "MELODY";
    Tracks[61].playlist_name1 = "ROMANTIC ACOUSTICS";
    Tracks[61].url = "https://www.youtube.com/watch?v=8T7WQrcyE9s";

    Tracks[62].index = 162;
    Tracks[62].name = "DOPE TRACK";
    Tracks[62].artist_name = "YUVAN SHANKAR RAJA";
    Tracks[62].album_name = "PYAAR PREMA KAADHAL";
    Tracks[62].genre_name = "MOOD";
    Tracks[62].playlist_name1 = "ROMANTIC ACOUSTICS";
    Tracks[62].playlist_name2 = "INIYA IRAVU";
    Tracks[62].url = "https://www.youtube.com/watch?v=SSrdUo0IrAc";

    Tracks[63].index = 163;
    Tracks[63].name = "OTHAYADI PAATHAIYILE";
    Tracks[63].artist_name = "ANIRUDH RAVICHANDER";
    Tracks[63].album_name = "KANAA";
    Tracks[63].genre_name = "LOVE";
    Tracks[63].playlist_name1 = "ROMANTIC ACOUSTICS";
    Tracks[63].url = "https://www.youtube.com/watch?v=qP8e7lFdEho";

    Tracks[64].index = 164;
    Tracks[64].name = "TAK BAK";
    Tracks[64].artist_name = "ANIRUDH RAVICHANDER";
    Tracks[64].album_name = "THANGAMAGAN";
    Tracks[64].genre_name = "LOVE";
    Tracks[64].playlist_name1 = "ROMANTIC ACOUSTICS";
    Tracks[64].url = "https://www.youtube.com/watch?v=Zl7B70EQeVo";

    Tracks[65].index = 165;
    Tracks[65].name = "MAYA NADHI";
    Tracks[65].artist_name = "SANTHOSH NARAYANAN";
    Tracks[65].album_name = "KABALI";
    Tracks[65].genre_name = "MELODY";
    Tracks[65].playlist_name1 = "ROMANTIC ACOUSTICS";
    Tracks[65].playlist_name2 = "INIYA IRAVU";
    Tracks[65].url = "https://www.youtube.com/watch?v=9cHXA6l4e4Q";

    Tracks[66].index = 166;
    Tracks[66].name = "KAADHAL ORU";
    Tracks[66].artist_name = "HARRIS JAYARAJ";
    Tracks[66].album_name = "OK OK";
    Tracks[66].genre_name = "LOVE";
    Tracks[66].playlist_name1 = "ROMANTIC ACOUSTICS";
    Tracks[66].url = "https://www.youtube.com/watch?v=xAfHFFi0O6E";

    Tracks[67].index = 167;
    Tracks[67].name = "POOKKAL POOKKUM";
    Tracks[67].artist_name = "G.V.PRAKASH KUMAR";
    Tracks[67].album_name = "MADARASAPATTINAM";
    Tracks[67].genre_name = "MELODY";
    Tracks[67].playlist_name1 = "INIYA IRAVU";
    Tracks[67].url = "https://www.youtube.com/watch?v=nWxGhq_lBII";

    Tracks[68].index = 168;
    Tracks[68].name = "KANNANA KANNEY";
    Tracks[68].artist_name = "D.IMMAN";
    Tracks[68].album_name = "VISWASAM";
    Tracks[68].genre_name = "MELODY";
    Tracks[68].playlist_name1 = "INYA IRAVU";
    Tracks[68].url = "https://www.youtube.com/watch?v=FysV6XnDlQk";

    Tracks[69].index = 169;
    Tracks[69].name = "NEETHANE";
    Tracks[69].artist_name = "A.R.RAHMAN";
    Tracks[69].album_name = "MERSAL";
    Tracks[69].genre_name = "MELODY";
    Tracks[69].playlist_name1 = "INIYA IRAVU";
    Tracks[69].url = "https://www.youtube.com/watch?v=fWajtP80g54";

    Tracks[70].index = 170;
    Tracks[70].name = "NAAN UN";
    Tracks[70].artist_name = "A.R.RAHMAN";
    Tracks[70].album_name = "24";
    Tracks[70].genre_name = "MELODY";
    Tracks[70].playlist_name1 = "INIYA IRAVU";
    Tracks[70].url = "https://www.youtube.com/watch?v=jRDCWQP7rjI";

    Tracks[71].index = 171;
    Tracks[71].name = "YAANJI";
    Tracks[71].artist_name = "ANIRUDH RAVICHANDER";
    Tracks[71].album_name = "VIKRAM VEDHA";
    Tracks[71].genre_name = "LOVE";
    Tracks[71].playlist_name1 = "INIYA IRAVU";
    Tracks[71].url = "https://www.youtube.com/watch?v=Y3-PeuQ7nvY";

    Tracks[72].index = 172;
    Tracks[72].name = "KAADHAL VAITHU";
    Tracks[72].artist_name = "YUVAN SHANKAR RAJA";
    Tracks[72].album_name = "DEEPAVALI";
    Tracks[72].genre_name = "MOOD";
    Tracks[72].playlist_name1 = "INIYA IRAVU";
    Tracks[72].url = "https://www.youtube.com/watch?v=F-nbd9_fxE0";

    Tracks[73].index = 173;
    Tracks[73].name = "NEEYUM NAANUM";
    Tracks[73].artist_name = "ANIRUDH RAVICHANDER";
    Tracks[73].album_name = "NAANUM ROWDY THAAN";
    Tracks[73].genre_name = "LOVE";
    Tracks[73].playlist_name1 = "INIYA IRAVU";
    Tracks[73].url = "https://www.youtube.com/watch?v=fYkQzTAx3Yo";

    Tracks[74].index = 174;
    Tracks[74].name = "NEEYUM NAANUM ANBE";
    Tracks[74].artist_name = "HIP HOP THAMIZHA";
    Tracks[74].album_name = "IMAIKKA NODIGAL";
    Tracks[74].genre_name = "LOVE";
    Tracks[74].playlist_name1 = "INIYA IRAVU";
    Tracks[74].url = "https://www.youtube.com/watch?v=dImiR3Sr8Wo";

    Tracks[75].index = 175;
    Tracks[75].name = "ANBAE PERANBAE";
    Tracks[75].artist_name = "SID SRIRAM";
    Tracks[75].album_name = "NGK";
    Tracks[75].genre_name = "LOVE";
    Tracks[75].playlist_name1 = "INIYA IRAVU";
    Tracks[75].url = "https://www.youtube.com/watch?v=N_iW0VC3IdI";

    Tracks[76].index = 176;
    Tracks[76].name = "MAARIS ANANDHI";
    Tracks[76].artist_name = "YUVAN SHANKAR RAJA";
    Tracks[76].album_name = "MAARI 2";
    Tracks[76].genre_name = "MELODY";
    Tracks[76].playlist_name1 = "INIYA IRAVU";
    Tracks[76].url = "https://www.youtube.com/watch?v=AGiVsZGmkJU";

    Tracks[77].index = 177;
    Tracks[77].name = "INNUM KONJA NERAM";
    Tracks[77].artist_name = "A.R.RAHMAN";
    Tracks[77].album_name = "MARYAN";
    Tracks[77].genre_name = "MELODY";
    Tracks[77].playlist_name1 = "INIYA IRAVU";
    Tracks[77].url = "https://www.youtube.com/watch?v=I8UrKhurkuk";

    Tracks[78].index = 178;
    Tracks[78].name = "UN MELA ORU KANNU";
    Tracks[78].artist_name = "D.IMMAN";
    Tracks[78].album_name = "RAJINI MURUGAN";
    Tracks[78].genre_name = "LOVE";
    Tracks[78].playlist_name1 = "INIYA IRAVU";
    Tracks[78].url = "https://www.youtube.com/watch?v=nngwP1WWva4";

    Tracks[79].index = 179;
    Tracks[79].name = "AYYAYO";
    Tracks[79].artist_name = "G.V.PRAKASH KUMAR";
    Tracks[79].album_name = "AADUKALAM";
    Tracks[79].genre_name = "MELODY";
    Tracks[79].playlist_name1 = "INIYA IRAVU";
    Tracks[79].url = "https://www.youtube.com/watch?v=uxb-TMoqb9k";

    Tracks[80].index = 180;
    Tracks[80].name = "ENKEYOO PAARTHA";
    Tracks[80].artist_name = "YUVAN SHANKAR RAJA";
    Tracks[80].album_name = "YAARADI NEE MOHINI";
    Tracks[80].genre_name = "MOOD";
    Tracks[80].playlist_name1 = "INIYA IRAVU";
    Tracks[80].url = "https://www.youtube.com/watch?v=tK6Cq1B-J1Q";

    Tracks[81].index = 181;
    Tracks[81].name = "CHILLENA";
    Tracks[81].artist_name = "G.V.PRAKASH KUMAR";
    Tracks[81].album_name = "RAJA RANI";
    Tracks[81].genre_name = "LOVE";
    Tracks[81].playlist_name1 = "INIYA IRAVU";
    Tracks[81].url = "https://www.youtube.com/watch?v=kQBuN9e_qbU";

    Tracks[82].index = 182;
    Tracks[82].name = "IDHAZHIN ORAM";
    Tracks[82].artist_name = "ANIRUDH RAVICHANDER";
    Tracks[82].album_name = "THREE";
    Tracks[82].genre_name = "MELODY";
    Tracks[82].playlist_name1 = "INIYA IRAVU";
    Tracks[82].url = "https://www.youtube.com/watch?v=lZORMUufA_Y";

    Tracks[83].index = 183;
    Tracks[83].name = "THULI THULI";
    Tracks[83].artist_name = "YUVAN SHANKAR RAJA";
    Tracks[83].album_name = "PAIYA";
    Tracks[83].genre_name = "LOVE";
    Tracks[83].playlist_name1 = "INIYA IRAVU";
    Tracks[83].url = "https://www.youtube.com/watch?v=v-hL3sks2qI";

    Tracks[84].index = 184;
    Tracks[84].name = "GULEBA";
    Tracks[84].artist_name = "ANIRUDH RAVICHANDER";
    Tracks[84].album_name = "GULEBAGAVALI";
    Tracks[84].genre_name = "PARTY";
    Tracks[84].playlist_name1 = "PARTY TONIGHT";
    Tracks[84].url = "https://www.youtube.com/watch?v=QVgSyvzmbxw";

    Tracks[85].index = 185;
    Tracks[85].name = "SINGLE PASANGA";
    Tracks[85].artist_name = "HIP HOP THAMIZHA";
    Tracks[85].album_name = "NATPE THUNAI";
    Tracks[85].genre_name = "PARTY";
    Tracks[85].playlist_name1 = "PARTY TONIGHT";
    Tracks[85].url = "https://www.youtube.com/watch?v=ybxt5dBVg5w";

    Tracks[86].index = 186;
    Tracks[86].name = "BIGIL BIGIL BIGILUMA";
    Tracks[86].artist_name = "A.R.RAHMAN";
    Tracks[86].album_name = "BIGIL";
    Tracks[86].genre_name = "PARTY";
    Tracks[86].playlist_name1 = "PARTY TONIGHT";
    Tracks[86].url = "https://www.youtube.com/watch?v=wHhUta4UAq0";

    Tracks[87].index = 187;
    Tracks[87].name = "USURE";
    Tracks[87].artist_name = "G.V.PRAKASH KUMAR";
    Tracks[87].album_name = "SIVAPU MANJAL PACHAI";
    Tracks[87].genre_name = "MELODY";
    Tracks[87].playlist_name1 = "INIYA IRAVU";
    Tracks[87].url = "https://www.youtube.com/watch?v=27U4UPhHqjE";

    Tracks[88].index = 188;
    Tracks[88].name = "MARANA MASS";
    Tracks[88].artist_name = "ANIRUDH RAVICHANDER";
    Tracks[88].album_name = "PETTA";
    Tracks[88].genre_name = "PARTY";
    Tracks[88].playlist_name1 = "PARTY TONIGHT";
    Tracks[88].url = "https://www.youtube.com/watch?v=88iypMO9H7g";

    Tracks[89].index = 189;
    Tracks[89].name = "BAGULU ODAYUM DAGULU MAARI";
    Tracks[89].artist_name = "ANIRUDH RAVICHANDER";
    Tracks[89].album_name = "MAARI";
    Tracks[89].genre_name = "PARTY";
    Tracks[89].playlist_name1 = "PARTY TONIGHT";
    Tracks[89].url = "https://www.youtube.com/watch?v=PKQNh8dVp2U";

    Tracks[90].index = 190;
    Tracks[90].name = "PAISA NOTE";
    Tracks[90].artist_name = "HIP HOP THAMIZHA";
    Tracks[90].album_name = "COMALI";
    Tracks[90].genre_name = "PARTY";
    Tracks[90].playlist_name1 = "PARTY TONIGHT";
    Tracks[90].url = "https://www.youtube.com/watch?v=lPg2iuMAdLc";

    Tracks[91].index = 191;
    Tracks[91].name = "UDHUNGADA SANGU";
    Tracks[91].artist_name = "ANIRUDH RAVICHANDER";
    Tracks[91].album_name = "VIP";
    Tracks[91].genre_name = "PARTY";
    Tracks[91].playlist_name1 = "PARTY TONIGHT";
    Tracks[91].url = "https://www.youtube.com/watch?v=RCXzH27eOIA";

    Tracks[92].index = 192;
    Tracks[92].name = "ROWDY BABY";
    Tracks[92].artist_name = "DHANUSH";
    Tracks[92].album_name = "MAARI 2";
    Tracks[92].genre_name = "PARTY";
    Tracks[92].playlist_name1 = "PARTY TONIGHT";
    Tracks[92].url = "https://www.youtube.com/watch?v=x6Q7c9RyMzk";

    Tracks[93].index = 193;
    Tracks[93].name = "SODAKKU";
    Tracks[93].artist_name = "ANIRUDH RAVICHANDER";
    Tracks[93].album_name = "THAANA SERNDHA KOOTAM";
    Tracks[93].genre_name = "FOLK";
    Tracks[93].playlist_name1 = "PARTY TONIGHT";
    Tracks[93].url = "https://www.youtube.com/watch?v=pn6M7_L1JbQ";

    Tracks[94].index = 194;
    Tracks[94].name = "THE MAARI SWAG";
    Tracks[94].artist_name = "ANIRUDH RAVICHANDER";
    Tracks[94].album_name = "MAARI";
    Tracks[94].genre_name = "PARTY";
    Tracks[94].playlist_name1 = "PARTY TONIGHT";
    Tracks[94].url = "https://www.youtube.com/watch?v=AeY7_k77zKg";

    Tracks[95].index = 195;
    Tracks[95].name = "TAKKUNU TAKKUNU";
    Tracks[95].artist_name = "HIP HOP THAMZIHA";
    Tracks[95].album_name = "MR.LOCAL";
    Tracks[95].genre_name = "LOVE";
    Tracks[95].playlist_name1 = "PARTY TONIGHT";
    Tracks[95].url = "https://www.youtube.com/watch?v=meITXEnkPaA";

    Tracks[96].index = 196;
    Tracks[96].name = "OTHA SOLLALA";
    Tracks[96].artist_name = "G.V.PRAKASH KUMAR";
    Tracks[96].album_name = "AADUKALAM";
    Tracks[96].genre_name = "FOLK";
    Tracks[96].playlist_name1 = "PARTY TONIGHT";
    Tracks[96].url = "https://www.youtube.com/watch?v=vXLAIaSkFIQ";

    Tracks[97].index = 197;
    Tracks[97].name = "DON'U DON'U DON'U";
    Tracks[97].artist_name = "ANIRUDH RAVICHANDER";
    Tracks[97].album_name = "MAARI";
    Tracks[97].genre_name = "LOVE";
    Tracks[97].playlist_name1 = "PARTY TONIGHT";
    Tracks[97].url = "https://www.youtube.com/watch?v=A_z5g0_hJN8";

    Tracks[98].index = 198;
    Tracks[98].name = "KARUTHAVANLAAM GALEEJAAM";
    Tracks[98].artist_name = "ANIRUDH RAVICHANDER";
    Tracks[98].album_name = "VELAIKARAN";
    Tracks[98].genre_name = "FOLK";
    Tracks[98].playlist_name1 = "PARTY TONIGHT";
    Tracks[98].url = "https://www.youtube.com/watch?v=es-5OLRrUf8";

    Tracks[99].index = 199;
    Tracks[99].name = "MAARI THARA LOCAL";
    Tracks[99].artist_name = "DHANUSH";
    Tracks[99].album_name = "MAARI";
    Tracks[99].genre_name = "FOLK";
    Tracks[99].playlist_name1 = "PARTY TONIGHT";
    Tracks[99].url = "https://www.youtube.com/watch?v=OViH68fJUhM";

    Tracks[100].index = 200;
    Tracks[100].name = "WHAT A KARVAAD";
    Tracks[100].artist_name = "DHANUSH";
    Tracks[100].album_name = "VIP";
    Tracks[100].genre_name = "FOLK";
    Tracks[100].playlist_name1 = "PARTY TONIGHT";
    Tracks[100].url = "https://www.youtube.com/watch?v=P2YRN8iGQ6g";

    Tracks[101].index = 201;
    Tracks[101].name = "AALUMA DOLUMA";
    Tracks[101].artist_name = "ANIRUDH RAVICHANDER";
    Tracks[101].album_name = "VEDHALAM";
    Tracks[101].genre_name = "FOLK";
    Tracks[101].playlist_name1 = "PARTY TONIGHT";
    Tracks[101].url = "https://www.youtube.com/watch?v=2ogKpj5QuSY";

    Tracks[102].index = 202;
    Tracks[102].name = "MERSALAAYITTEN";
    Tracks[102].artist_name = "A.R.RAHMAN";
    Tracks[102].album_name = "I";
    Tracks[102].genre_name = "LOVE";
    Tracks[102].playlist_name1 = "PARTY TOBIGHT";
    Tracks[102].url = "https://www.youtube.com/watch?v=uI_ug1H6u0k";

    Tracks[103].index = 203;
    Tracks[103].name = "NAHNA NA NAH";
    Tracks[103].artist_name = "YUVAN SHANKAR RAJA";
    Tracks[103].album_name = "BIRIYANI";
    Tracks[103].genre_name = "PARTY";
    Tracks[103].playlist_name1 = "PARTY TONIGHT";
    Tracks[103].url = "https://www.youtube.com/watch?v=iyTMlo5uuzU";

    Tracks[104].index = 204;
    Tracks[104].name = "HEARTUKULLA";
    Tracks[104].artist_name = "VIVEK-MERVIN";
    Tracks[104].album_name = "GULEBAGAVALI";
    Tracks[104].genre_name = "PARTY";
    Tracks[104].playlist_name1 = "PARTY TONIGHT";
    Tracks[104].url = "https://www.youtube.com/watch?v=OOP4FDO1XeU";

    Tracks[105].index = 205;
    Tracks[105].name = "DANDANAKKA";
    Tracks[105].artist_name = "D.IMMAN";
    Tracks[105].album_name = "ROMEO JULIET";
    Tracks[105].genre_name = "FOLK";
    Tracks[105].playlist_name1 = "PARTY TONIGHT";
    Tracks[105].url = "https://www.youtube.com/watch?v=1zRe8UPF1tM";

    Tracks[106].index = 206;
    Tracks[106].name = "TASAKKU TASAKKU";
    Tracks[106].artist_name = "SAM.C.S";
    Tracks[106].album_name = "VIKRAM VEDHA";
    Tracks[106].genre_name = "PARTY";
    Tracks[106].playlist_name1 = "PARTY TONIGHT";
    Tracks[106].url = "https://www.youtube.com/watch?v=Rw3ePD8qLcc";

    Tracks[107].index = 207;
    Tracks[107].name = "CHENNAI CITY GANGSTA";
    Tracks[107].artist_name = "ANIRUDH RAVICHANDER";
    Tracks[107].album_name = "VANAKKAM CHENNAI";
    Tracks[107].genre_name = "PARTY";
    Tracks[107].playlist_name1 = "PARTY TONIGHT";
    Tracks[107].url = "https://www.youtube.com/watch?v=hAn75DAONqs";

    Tracks[108].index = 208;
    Tracks[108].name = "VILAYAADU MANKATHA";
    Tracks[108].artist_name = "YUVAN SHANKAR RAJA";
    Tracks[108].album_name = "MANKATHA";
    Tracks[108].genre_name = "PARTY";
    Tracks[108].playlist_name1 = "PARTY TONIGHT";
    Tracks[108].url = "https://www.youtube.com/watch?v=fhdLTvl9a74";

    Tracks[109].index = 209;
    Tracks[109].name = "DAAVUYA";
    Tracks[109].artist_name = "SANTHOSH NARAYANAN";
    Tracks[109].album_name = "REMO";
    Tracks[109].genre_name = "PARTY";
    Tracks[109].playlist_name1 = "PARTY TONIGHT";
    Tracks[109].url = "https://www.youtube.com/watch?v=GRKyx31fqjE";

    Tracks[110].index = 210;
    Tracks[110].name = "LOCAL BOYS";
    Tracks[110].artist_name = "DHANUSH";
    Tracks[110].album_name = "ETHIR NEECHAL";
    Tracks[110].genre_name = "PARTY";
    Tracks[110].playlist_name1 = "PARTY TONIGHT";
    Tracks[110].url = "https://www.youtube.com/watch?v=0FsPYnmjkN4";

    Tracks[111].index = 211;
    Tracks[111].name = "MACHI OPEN THE BOTTLE";
    Tracks[111].artist_name = "YUVAN SHANKAR RAJA";
    Tracks[111].album_name = "MANKATHA";
    Tracks[111].genre_name = "PARTY";
    Tracks[111].playlist_name1 = "PARTY TONIGHT";
    Tracks[111].url = "https://www.youtube.com/watch?v=68ixlbMQaY0";

    Tracks[112].index = 212;
    Tracks[112].name = "SONAPAREEYA";
    Tracks[112].artist_name = "A.R.RAHMAN";
    Tracks[112].album_name = "MARYAN";
    Tracks[112].genre_name = "PARTY";
    Tracks[112].playlist_name1 = "PARTY TONIGHT";
    Tracks[112].url = "https://www.youtube.com/watch?v=NZE6pFlnSeU";

    //inserting tracks to BP Trees

    for (int i = 0; i < 113; i++)
    {
        if (Tracks[i].playlist_name1 == "LATEST TAMIL" || Tracks[i].playlist_name2 == "LATEST TAMIL" || Tracks[i].playlist_name3 == "LATEST TAMIL")
        {
            LatestTamil.insert(Tracks[i].index, &Tracks[i]);
        }
        if (Tracks[i].playlist_name1 == "HEART BREAKERS" || Tracks[i].playlist_name2 == "HEART BREAKERS" || Tracks[i].playlist_name3 == "HEART BREAKERS")
        {
            HeartBreakers.insert(Tracks[i].index, &Tracks[i]);
        }
        if (Tracks[i].playlist_name1 == "ROMANTIC ACOUSTICS" || Tracks[i].playlist_name2 == "ROMANTIC ACOUSTICS" || Tracks[i].playlist_name3 == "ROMANTIC ACOUSTICS")
        {
            RomanticAcoustics.insert(Tracks[i].index, &Tracks[i]);
        }
        if (Tracks[i].playlist_name1 == "INIYA IRAVU" || Tracks[i].playlist_name2 == "INIYA IRAVU" || Tracks[i].playlist_name3 == "INIYA IRAVU")
        {
            IniyaIravu.insert(Tracks[i].index, &Tracks[i]);
        }
        if (Tracks[i].playlist_name1 == "PARTY TONIGHT" || Tracks[i].playlist_name2 == "PARTY TONIGHT" || Tracks[i].playlist_name3 == "PARTY TONIGHT")
        {
            PartyTonight.insert(Tracks[i].index, &Tracks[i]);
        }
        if (Tracks[i].artist_name == "ANIRUDH RAVICHANDER")
        {
            AR.insert(Tracks[i].index, &Tracks[i]);
        }
        if (Tracks[i].artist_name == "G.V.PRAKASH KUMAR")
        {
            GV.insert(Tracks[i].index, &Tracks[i]);
        }
        if (Tracks[i].artist_name == "BENNY DAYAL")
        {
            BD.insert(Tracks[i].index, &Tracks[i]);
        }
        if (Tracks[i].artist_name == "LEON JAMES")
        {
            LJ.insert(Tracks[i].index, &Tracks[i]);
        }
        if (Tracks[i].artist_name == "SID SRIRAM")
        {
            SS.insert(Tracks[i].index, &Tracks[i]);
        }
        if (Tracks[i].artist_name == "HIP HOP THAMIZHA")
        {
            HHT.insert(Tracks[i].index, &Tracks[i]);
        }
        if (Tracks[i].artist_name == "DHANUSH")
        {
            DH.insert(Tracks[i].index, &Tracks[i]);
        }
        if (Tracks[i].artist_name == "YUVAN SHANKAR RAJA")
        {
            YSR.insert(Tracks[i].index, &Tracks[i]);
        }
        if (Tracks[i].artist_name == "SANTHOSH NARAYANAN")
        {
            SN.insert(Tracks[i].index, &Tracks[i]);
        }
        if (Tracks[i].artist_name == "DHURV VIKRAM")
        {
            DV.insert(Tracks[i].index, &Tracks[i]);
        }
        if (Tracks[i].artist_name == "D.IMMAN")
        {
            DI.insert(Tracks[i].index, &Tracks[i]);
        }
        if (Tracks[i].artist_name == "HARRIS JAYARAJ")
        {
            HJ.insert(Tracks[i].index, &Tracks[i]);
        }
        if (Tracks[i].artist_name == "VIVEK-MERVIN")
        {
            VM.insert(Tracks[i].index, &Tracks[i]);
        }
        if (Tracks[i].artist_name == "SAM.C.S")
        {
            SCS.insert(Tracks[i].index, &Tracks[i]);
        }
        if (Tracks[i].artist_name == "A.R.RAHMAN")
        {
            ARR.insert(Tracks[i].index, &Tracks[i]);
        }
        if (Tracks[i].genre_name == "PARTY")
        {
            Party.insert(Tracks[i].index, &Tracks[i]);
        }
        if (Tracks[i].genre_name == "MELODY")
        {
            Melody.insert(Tracks[i].index, &Tracks[i]);
        }
        if (Tracks[i].genre_name == "LOVE")
        {
            Love.insert(Tracks[i].index, &Tracks[i]);
        }
        if (Tracks[i].genre_name == "MOOD")
        {
            Mood.insert(Tracks[i].index, &Tracks[i]);
        }
        if (Tracks[i].genre_name == "RAP")
        {
            Rap.insert(Tracks[i].index, &Tracks[i]);
        }
        if (Tracks[i].genre_name == "FOLK")
        {
            Folk.insert(Tracks[i].index, &Tracks[i]);
        }
    }

    // Introduction and instructions

    cout << "\t\t\t\t\t\t->->->->->Welcome to the Music Player<-<-<-<-<-" << endl;
    cout << "\t\tThis player consists of collection of over hundred songs from over 60 albums and 15 different artists and various genres" << endl;
    cout << "\t\tIn this player the user can listen to songs from the above mentioned categories" << endl;
    cout << "\t\tThe user interface will be menu driven and the user can select the from the menu" << endl;
    cout << "\t\tWhen the user wants to open a track it will be opened on the browser" << endl;
    cout << "\t\tMultiple tracks can be opened in succession" << endl;
    cout << "\t\tMain menu:" << endl;
    cout << "\t\t1. Search songs using Artists" << endl;
    cout << "\t\t2. Search songs using Readymade playlists" << endl;
    cout << "\t\t3. Search songs using Genre" << endl;
    cout << "\t\tEnter the option:";
    cin >> opt;

    switch (opt)
    {
    case 1:
        cout << "\tThe artists whose songs are available are:" << endl;
        cout << "\tArtist menu->" << endl;
        cout << "\t1. Anirudh Ravichander" << endl;
        cout << "\t2. G.V.Prakash kumar" << endl;
        cout << "\t3. Benny Dayal" << endl;
        cout << "\t4. Leon James" << endl;
        cout << "\t5. Sid Sriram" << endl;
        cout << "\t6. Hip Hop Thamizha" << endl;
        cout << "\t7. Dhanush" << endl;
        cout << "\t8. Yuvan Shankar Raja" << endl;
        cout << "\t9. Santhosh Narayanan" << endl;
        cout << "\t10.Dhruv Vikram" << endl;
        cout << "\t11.D.Imman" << endl;
        cout << "\t12.Harris Jayaraj" << endl;
        cout << "\t13.Vivek-Mervin" << endl;
        cout << "\t14.Sam.C.S" << endl;
        cout << "\t15.A.R.Rahman" << endl;
        cout << "\tEnter the artist from which you want to choose the track(option)";
        cin >> opt1;
        switch (opt1)
        {
        case 1:
            f = 0, nxt = 0;
            trv = 0;
            count = 0;
            cout << "\tSongs are listed below:" << endl;
            for (trv = 0; trv < 113; trv++)
            {
                if (Tracks[trv].artist_name == "ANIRUDH RAVICHANDER")
                {
                    ind[count] = Tracks[trv].index;
                    cout << "\tIndex No." << Tracks[trv].index << endl;
                    cout << "\tName:" << Tracks[trv].name << endl;
                    cout << "\tAlbum:" << Tracks[trv].album_name << endl;
                    cout << "\tGenre:" << Tracks[trv].genre_name << endl;
                    cout << endl;
                    count++;
                }
            }
        ar:
            cout << "Enter the index number of the desired track:";
            cin >> opt2;
            for (i = 0; ind[i] != 0; i++)
            {
                if (ind[i] == opt2)
                {
                    f = 1;
                }
            }
            cout << f;
            if (f == 1)
            {
                find = AR.search(opt2, tra);
                cout << " Opening the track in YouTube..." << endl;
                ShellExecuteA(NULL, verb, find->url, NULL, NULL, SW_SHOWNORMAL);
                cout << " Want to play next track in this playlist?(Y/N)";
                cin >> ch;
                cout << endl;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << " Opening next track..." << endl;
                    ShellExecuteA(NULL, verb, tra[nxt]->url, NULL, NULL, SW_SHOWNORMAL);
                    nxt++;
                }
            }
            else
            {
                cout << " Invalid Option..." << endl;
                goto ar;
            }
            break;

        case 2:
            f = 0, nxt = 0;
            trv = 0;
            count = 0;
            cout << "\tSongs are listed below:" << endl;
            for (trv = 0; trv < 113; trv++)
            {
                if (Tracks[trv].artist_name == "G.V.PRAKASH KUMAR")
                {
                    ind[count] = Tracks[trv].index;
                    cout << "\tIndex No." << Tracks[trv].index << endl;
                    cout << "\tName:" << Tracks[trv].name << endl;
                    cout << "\tAlbum:" << Tracks[trv].album_name << endl;
                    cout << "\tGenre:" << Tracks[trv].genre_name << endl;
                    cout << endl;
                    count++;
                }
            }
        gv:
            cout << "Enter the index number of the desired track:";
            cin >> opt2;
            for (i = 0; ind[i] != 0; i++)
            {
                if (ind[i] == opt2)
                {
                    f = 1;
                }
            }
            cout << f;
            if (f == 1)
            {
                find = GV.search(opt2, tra);
                cout << " Opening the track in YouTube..." << endl;
                ShellExecuteA(NULL, verb, find->url, NULL, NULL, SW_SHOWNORMAL);
                cout << " Want to play next track in this playlist?(Y/N)";
                cin >> ch;
                cout << endl;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << " Opening next track..." << endl;
                    ShellExecuteA(NULL, verb, tra[nxt]->url, NULL, NULL, SW_SHOWNORMAL);
                    nxt++;
                }
            }
            else
            {
                cout << " Invalid Option..." << endl;
                goto gv;
            }
            break;

        case 3:
            f = 0, nxt = 0;
            trv = 0;
            count = 0;
            cout << "\tSongs are listed below:" << endl;
            for (trv = 0; trv < 113; trv++)
            {
                if (Tracks[trv].artist_name == "BENNY DAYAL")
                {
                    ind[count] = Tracks[trv].index;
                    cout << "\tIndex No." << Tracks[trv].index << endl;
                    cout << "\tName:" << Tracks[trv].name << endl;
                    cout << "\tAlbum:" << Tracks[trv].album_name << endl;
                    cout << "\tGenre:" << Tracks[trv].genre_name << endl;
                    cout << endl;
                    count++;
                }
            }
        bd:
            cout << "Enter the index number of the desired track:";
            cin >> opt2;
            for (i = 0; ind[i] != 0; i++)
            {
                if (ind[i] == opt2)
                {
                    f = 1;
                }
            }
            cout << f;
            if (f == 1)
            {
                find = BD.search(opt2, tra);
                cout << " Opening the track in YouTube..." << endl;
                ShellExecuteA(NULL, verb, find->url, NULL, NULL, SW_SHOWNORMAL);
                cout << " Want to play next track in this playlist?(Y/N)";
                cin >> ch;
                cout << endl;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << " Opening next track..." << endl;
                    ShellExecuteA(NULL, verb, tra[nxt]->url, NULL, NULL, SW_SHOWNORMAL);
                    nxt++;
                }
            }
            else
            {
                cout << " Invalid Option..." << endl;
                goto bd;
            }
            break;

        case 4:
            f = 0, nxt = 0;
            trv = 0;
            count = 0;
            cout << "\tSongs are listed below:" << endl;
            for (trv = 0; trv < 113; trv++)
            {
                if (Tracks[trv].artist_name == "LEON JAMES")
                {
                    ind[count] = Tracks[trv].index;
                    cout << "\tIndex No." << Tracks[trv].index << endl;
                    cout << "\tName:" << Tracks[trv].name << endl;
                    cout << "\tAlbum:" << Tracks[trv].album_name << endl;
                    cout << "\tGenre:" << Tracks[trv].genre_name << endl;
                    cout << endl;
                    count++;
                }
            }
        lj:
            cout << "Enter the index number of the desired track:";
            cin >> opt2;
            for (i = 0; ind[i] != 0; i++)
            {
                if (ind[i] == opt2)
                {
                    f = 1;
                }
            }
            cout << f;
            if (f == 1)
            {
                find = LJ.search(opt2, tra);
                cout << " Opening the track in YouTube..." << endl;
                ShellExecuteA(NULL, verb, find->url, NULL, NULL, SW_SHOWNORMAL);
                cout << " Want to play next track in this playlist?(Y/N)";
                cin >> ch;
                cout << endl;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << " Opening next track..." << endl;
                    ShellExecuteA(NULL, verb, tra[nxt]->url, NULL, NULL, SW_SHOWNORMAL);
                    nxt++;
                }
            }
            else
            {
                cout << " Invalid Option..." << endl;
                goto lj;
            }
            break;

        case 5:
            f = 0, nxt = 0;
            trv = 0;
            count = 0;
            cout << "\tSongs are listed below:" << endl;
            for (trv = 0; trv < 113; trv++)
            {
                if (Tracks[trv].artist_name == "SID SRIRAM")
                {
                    ind[count] = Tracks[trv].index;
                    cout << "\tIndex No." << Tracks[trv].index << endl;
                    cout << "\tName:" << Tracks[trv].name << endl;
                    cout << "\tAlbum:" << Tracks[trv].album_name << endl;
                    cout << "\tGenre:" << Tracks[trv].genre_name << endl;
                    cout << endl;
                    count++;
                }
            }
        ss:
            cout << "Enter the index number of the desired track:";
            cin >> opt2;
            for (i = 0; ind[i] != 0; i++)
            {
                if (ind[i] == opt2)
                {
                    f = 1;
                }
            }
            cout << f;
            if (f == 1)
            {
                find = SS.search(opt2, tra);
                cout << " Opening the track in YouTube..." << endl;
                ShellExecuteA(NULL, verb, find->url, NULL, NULL, SW_SHOWNORMAL);
                cout << " Want to play next track in this playlist?(Y/N)";
                cin >> ch;
                cout << endl;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << " Opening next track..." << endl;
                    ShellExecuteA(NULL, verb, tra[nxt]->url, NULL, NULL, SW_SHOWNORMAL);
                    nxt++;
                }
            }
            else
            {
                cout << " Invalid Option..." << endl;
                goto ss;
            }
            break;

        case 6:
            f = 0, nxt = 0;
            trv = 0;
            count = 0;
            cout << "\tSongs are listed below:" << endl;
            for (trv = 0; trv < 113; trv++)
            {
                if (Tracks[trv].artist_name == "HIP HOP THAMIZHA")
                {
                    ind[count] = Tracks[trv].index;
                    cout << "\tIndex No." << Tracks[trv].index << endl;
                    cout << "\tName:" << Tracks[trv].name << endl;
                    cout << "\tAlbum:" << Tracks[trv].album_name << endl;
                    cout << "\tGenre:" << Tracks[trv].genre_name << endl;
                    cout << endl;
                    count++;
                }
            }
        hht:
            cout << "Enter the index number of the desired track:";
            cin >> opt2;
            for (i = 0; ind[i] != 0; i++)
            {
                if (ind[i] == opt2)
                {
                    f = 1;
                }
            }
            cout << f;
            if (f == 1)
            {
                find = GV.search(opt2, tra);
                cout << " Opening the track in YouTube..." << endl;
                ShellExecuteA(NULL, verb, find->url, NULL, NULL, SW_SHOWNORMAL);
                cout << " Want to play next track in this playlist?(Y/N)";
                cin >> ch;
                cout << endl;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << " Opening next track..." << endl;
                    ShellExecuteA(NULL, verb, tra[nxt]->url, NULL, NULL, SW_SHOWNORMAL);
                    nxt++;
                }
            }
            else
            {
                cout << " Invalid Option..." << endl;
                goto hht;
            }
            break;

        case 7:
            f = 0, nxt = 0;
            trv = 0;
            count = 0;
            cout << "\tSongs are listed below:" << endl;
            for (trv = 0; trv < 113; trv++)
            {
                if (Tracks[trv].artist_name == "DHANUSH")
                {
                    ind[count] = Tracks[trv].index;
                    cout << "\tIndex No." << Tracks[trv].index << endl;
                    cout << "\tName:" << Tracks[trv].name << endl;
                    cout << "\tAlbum:" << Tracks[trv].album_name << endl;
                    cout << "\tGenre:" << Tracks[trv].genre_name << endl;
                    cout << endl;
                    count++;
                }
            }
        dh:
            cout << "Enter the index number of the desired track:";
            cin >> opt2;
            for (i = 0; ind[i] != 0; i++)
            {
                if (ind[i] == opt2)
                {
                    f = 1;
                }
            }
            cout << f;
            if (f == 1)
            {
                find = DH.search(opt2, tra);
                cout << " Opening the track in YouTube..." << endl;
                ShellExecuteA(NULL, verb, find->url, NULL, NULL, SW_SHOWNORMAL);
                cout << " Want to play next track in this playlist?(Y/N)";
                cin >> ch;
                cout << endl;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << " Opening next track..." << endl;
                    ShellExecuteA(NULL, verb, tra[nxt]->url, NULL, NULL, SW_SHOWNORMAL);
                    nxt++;
                }
            }
            else
            {
                cout << " Invalid Option..." << endl;
                goto dh;
            }
            break;

        case 8:
            f = 0, nxt = 0;
            trv = 0;
            count = 0;
            cout << "\tSongs are listed below:" << endl;
            for (trv = 0; trv < 113; trv++)
            {
                if (Tracks[trv].artist_name == "YUVAN SHANKAR RAJA")
                {
                    ind[count] = Tracks[trv].index;
                    cout << "\tIndex No." << Tracks[trv].index << endl;
                    cout << "\tName:" << Tracks[trv].name << endl;
                    cout << "\tAlbum:" << Tracks[trv].album_name << endl;
                    cout << "\tGenre:" << Tracks[trv].genre_name << endl;
                    cout << endl;
                    count++;
                }
            }
        ysr:
            cout << "Enter the index number of the desired track:";
            cin >> opt2;
            for (i = 0; ind[i] != 0; i++)
            {
                if (ind[i] == opt2)
                {
                    f = 1;
                }
            }
            cout << f;
            if (f == 1)
            {
                find = YSR.search(opt2, tra);
                cout << " Opening the track in YouTube..." << endl;
                ShellExecuteA(NULL, verb, find->url, NULL, NULL, SW_SHOWNORMAL);
                cout << " Want to play next track in this playlist?(Y/N)";
                cin >> ch;
                cout << endl;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << " Opening next track..." << endl;
                    ShellExecuteA(NULL, verb, tra[nxt]->url, NULL, NULL, SW_SHOWNORMAL);
                    nxt++;
                }
            }
            else
            {
                cout << " Invalid Option..." << endl;
                goto ysr;
            }
            break;

        case 9:
            f = 0, nxt = 0;
            trv = 0;
            count = 0;
            cout << "\tSongs are listed below:" << endl;
            for (trv = 0; trv < 113; trv++)
            {
                if (Tracks[trv].artist_name == "SANTHOSH NARAYANAN")
                {
                    ind[count] = Tracks[trv].index;
                    cout << "\tIndex No." << Tracks[trv].index << endl;
                    cout << "\tName:" << Tracks[trv].name << endl;
                    cout << "\tAlbum:" << Tracks[trv].album_name << endl;
                    cout << "\tGenre:" << Tracks[trv].genre_name << endl;
                    cout << endl;
                    count++;
                }
            }
        sn:
            cout << "Enter the index number of the desired track:";
            cin >> opt2;
            for (i = 0; ind[i] != 0; i++)
            {
                if (ind[i] == opt2)
                {
                    f = 1;
                }
            }
            cout << f;
            if (f == 1)
            {
                find = SN.search(opt2, tra);
                cout << " Opening the track in YouTube..." << endl;
                ShellExecuteA(NULL, verb, find->url, NULL, NULL, SW_SHOWNORMAL);
                cout << " Want to play next track in this playlist?(Y/N)";
                cin >> ch;
                cout << endl;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << " Opening next track..." << endl;
                    ShellExecuteA(NULL, verb, tra[nxt]->url, NULL, NULL, SW_SHOWNORMAL);
                    nxt++;
                }
            }
            else
            {
                cout << " Invalid Option..." << endl;
                goto sn;
            }
            break;

        case 10:
            f = 0, nxt = 0;
            trv = 0;
            count = 0;
            cout << "\tSongs are listed below:" << endl;
            for (trv = 0; trv < 113; trv++)
            {
                if (Tracks[trv].artist_name == "DHRUV VIKRAM")
                {
                    ind[count] = Tracks[trv].index;
                    cout << "\tIndex No." << Tracks[trv].index << endl;
                    cout << "\tName:" << Tracks[trv].name << endl;
                    cout << "\tAlbum:" << Tracks[trv].album_name << endl;
                    cout << "\tGenre:" << Tracks[trv].genre_name << endl;
                    cout << endl;
                    count++;
                }
            }
        dv:
            cout << "Enter the index number of the desired track:";
            cin >> opt2;
            for (i = 0; ind[i] != 0; i++)
            {
                if (ind[i] == opt2)
                {
                    f = 1;
                }
            }
            cout << f;
            if (f == 1)
            {
                find = DV.search(opt2, tra);
                cout << " Opening the track in YouTube..." << endl;
                ShellExecuteA(NULL, verb, find->url, NULL, NULL, SW_SHOWNORMAL);
                cout << " Want to play next track in this playlist?(Y/N)";
                cin >> ch;
                cout << endl;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << " Opening next track..." << endl;
                    ShellExecuteA(NULL, verb, tra[nxt]->url, NULL, NULL, SW_SHOWNORMAL);
                    nxt++;
                }
            }
            else
            {
                cout << " Invalid Option..." << endl;
                goto dv;
            }
            break;

        case 11:
            f = 0, nxt = 0;
            trv = 0;
            count = 0;
            cout << "\tSongs are listed below:" << endl;
            for (trv = 0; trv < 113; trv++)
            {
                if (Tracks[trv].artist_name == "D.IMMAN")
                {
                    ind[count] = Tracks[trv].index;
                    cout << "\tIndex No." << Tracks[trv].index << endl;
                    cout << "\tName:" << Tracks[trv].name << endl;
                    cout << "\tAlbum:" << Tracks[trv].album_name << endl;
                    cout << "\tGenre:" << Tracks[trv].genre_name << endl;
                    cout << endl;
                    count++;
                }
            }
        di:
            cout << "Enter the index number of the desired track:";
            cin >> opt2;
            for (i = 0; ind[i] != 0; i++)
            {
                if (ind[i] == opt2)
                {
                    f = 1;
                }
            }
            cout << f;
            if (f == 1)
            {
                find = DI.search(opt2, tra);
                cout << " Opening the track in YouTube..." << endl;
                ShellExecuteA(NULL, verb, find->url, NULL, NULL, SW_SHOWNORMAL);
                cout << " Want to play next track in this playlist?(Y/N)";
                cin >> ch;
                cout << endl;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << " Opening next track..." << endl;
                    ShellExecuteA(NULL, verb, tra[nxt]->url, NULL, NULL, SW_SHOWNORMAL);
                    nxt++;
                }
            }
            else
            {
                cout << " Invalid Option..." << endl;
                goto di;
            }
            break;

        case 12:
            f = 0, nxt = 0;
            trv = 0;
            count = 0;
            cout << "\tSongs are listed below:" << endl;
            for (trv = 0; trv < 113; trv++)
            {
                if (Tracks[trv].artist_name == "HARRIS JAYARAJ")
                {
                    ind[count] = Tracks[trv].index;
                    cout << "\tIndex No." << Tracks[trv].index << endl;
                    cout << "\tName:" << Tracks[trv].name << endl;
                    cout << "\tAlbum:" << Tracks[trv].album_name << endl;
                    cout << "\tGenre:" << Tracks[trv].genre_name << endl;
                    cout << endl;
                    count++;
                }
            }
        hj:
            cout << "Enter the index number of the desired track:";
            cin >> opt2;
            for (i = 0; ind[i] != 0; i++)
            {
                if (ind[i] == opt2)
                {
                    f = 1;
                }
            }
            cout << f;
            if (f == 1)
            {
                find = HJ.search(opt2, tra);
                cout << " Opening the track in YouTube..." << endl;
                ShellExecuteA(NULL, verb, find->url, NULL, NULL, SW_SHOWNORMAL);
                cout << " Want to play next track in this playlist?(Y/N)";
                cin >> ch;
                cout << endl;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << " Opening next track..." << endl;
                    ShellExecuteA(NULL, verb, tra[nxt]->url, NULL, NULL, SW_SHOWNORMAL);
                    nxt++;
                }
            }
            else
            {
                cout << " Invalid Option..." << endl;
                goto hj;
            }
            break;

        case 13:
            f = 0, nxt = 0;
            trv = 0;
            count = 0;
            cout << "\tSongs are listed below:" << endl;
            for (trv = 0; trv < 113; trv++)
            {
                if (Tracks[trv].artist_name == "VIVEK-MERWIN")
                {
                    ind[count] = Tracks[trv].index;
                    cout << "\tIndex No." << Tracks[trv].index << endl;
                    cout << "\tName:" << Tracks[trv].name << endl;
                    cout << "\tAlbum:" << Tracks[trv].album_name << endl;
                    cout << "\tGenre:" << Tracks[trv].genre_name << endl;
                    cout << endl;
                    count++;
                }
            }
        vm:
            cout << "Enter the index number of the desired track:";
            cin >> opt2;
            for (i = 0; ind[i] != 0; i++)
            {
                if (ind[i] == opt2)
                {
                    f = 1;
                }
            }
            cout << f;
            if (f == 1)
            {
                find = VM.search(opt2, tra);
                cout << " Opening the track in YouTube..." << endl;
                ShellExecuteA(NULL, verb, find->url, NULL, NULL, SW_SHOWNORMAL);
                cout << " Want to play next track in this playlist?(Y/N)";
                cin >> ch;
                cout << endl;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << " Opening next track..." << endl;
                    ShellExecuteA(NULL, verb, tra[nxt]->url, NULL, NULL, SW_SHOWNORMAL);
                    nxt++;
                }
            }
            else
            {
                cout << " Invalid Option..." << endl;
                goto vm;
            }
            break;

        case 14:
            f = 0, nxt = 0;
            trv = 0;
            count = 0;
            cout << "\tSongs are listed below:" << endl;
            for (trv = 0; trv < 113; trv++)
            {
                if (Tracks[trv].artist_name == "SAM.C.S")
                {
                    ind[count] = Tracks[trv].index;
                    cout << "\tIndex No." << Tracks[trv].index << endl;
                    cout << "\tName:" << Tracks[trv].name << endl;
                    cout << "\tAlbum:" << Tracks[trv].album_name << endl;
                    cout << "\tGenre:" << Tracks[trv].genre_name << endl;
                    cout << endl;
                    count++;
                }
            }
        scs:
            cout << "Enter the index number of the desired track:";
            cin >> opt2;
            for (i = 0; ind[i] != 0; i++)
            {
                if (ind[i] == opt2)
                {
                    f = 1;
                }
            }
            cout << f;
            if (f == 1)
            {
                find = SCS.search(opt2, tra);
                cout << " Opening the track in YouTube..." << endl;
                ShellExecuteA(NULL, verb, find->url, NULL, NULL, SW_SHOWNORMAL);
                cout << " Want to play next track in this playlist?(Y/N)";
                cin >> ch;
                cout << endl;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << " Opening next track..." << endl;
                    ShellExecuteA(NULL, verb, tra[nxt]->url, NULL, NULL, SW_SHOWNORMAL);
                    nxt++;
                }
            }
            else
            {
                cout << " Invalid Option..." << endl;
                goto scs;
            }
            break;

        case 15:
            f = 0, nxt = 0;
            trv = 0;
            count = 0;
            cout << "\tSongs are listed below:" << endl;
            for (trv = 0; trv < 113; trv++)
            {
                if (Tracks[trv].artist_name == "A.R.RAHMAN")
                {
                    ind[count] = Tracks[trv].index;
                    cout << "\tIndex No." << Tracks[trv].index << endl;
                    cout << "\tName:" << Tracks[trv].name << endl;
                    cout << "\tAlbum:" << Tracks[trv].album_name << endl;
                    cout << "\tGenre:" << Tracks[trv].genre_name << endl;
                    cout << endl;
                    count++;
                }
            }
        arr:
            cout << "Enter the index number of the desired track:";
            cin >> opt2;
            for (i = 0; ind[i] != 0; i++)
            {
                if (ind[i] == opt2)
                {
                    f = 1;
                }
            }
            cout << f;
            if (f == 1)
            {
                find = ARR.search(opt2, tra);
                cout << " Opening the track in YouTube..." << endl;
                ShellExecuteA(NULL, verb, find->url, NULL, NULL, SW_SHOWNORMAL);
                cout << " Want to play next track in this playlist?(Y/N)";
                cin >> ch;
                cout << endl;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << " Opening next track..." << endl;
                    ShellExecuteA(NULL, verb, tra[nxt]->url, NULL, NULL, SW_SHOWNORMAL);
                    nxt++;
                }
            }
            else
            {
                cout << " Invalid Option..." << endl;
                goto arr;
            }
            break;
        }
        break;

    case 2:
        cout << "\tSelect the playlist you want to view" << endl;
        cout << "\t1. Latest Tamil" << endl;
        cout << "\t2. Heart Breakers" << endl;
        cout << "\t3. Romantic Acoustics" << endl;
        cout << "\t4. Iniya Iravu" << endl;
        cout << "\t5. Party Tonight" << endl;
        cout << "\tEnter the playlist you want to view(option):";
        cin >> opt3;
        switch (opt3)
        {
        case 1:
            f = 0, nxt = 0;
            trv = 0;
            count = 0;
            cout << "\tSongs are listed below:" << endl;
            for (trv = 0; trv < 113; trv++)
            {
                if (Tracks[trv].playlist_name1 == "LATEST TAMIL" || Tracks[trv].playlist_name2 == "LATEST TAMIL" || Tracks[trv].playlist_name3 == "LATEST TAMIL")
                {
                    ind[count] = Tracks[trv].index;
                    cout << "\tIndex No." << Tracks[trv].index << endl;
                    cout << "\tName:" << Tracks[trv].name << endl;
                    cout << "\tAlbum:" << Tracks[trv].album_name << endl;
                    cout << "\tGenre:" << Tracks[trv].genre_name << endl;
                    cout << endl;
                    count++;
                }
            }
        lt:
            cout << "Enter the index number of the desired track:";
            cin >> opt2;
            for (i = 0; ind[i] != 0; i++)
            {
                if (ind[i] == opt2)
                {
                    f = 1;
                }
            }
            cout << f;
            if (f == 1)
            {
                find = LatestTamil.search(opt2, tra);
                cout << " Opening the track in YouTube..." << endl;
                ShellExecuteA(NULL, verb, find->url, NULL, NULL, SW_SHOWNORMAL);
                cout << " Want to play next track in this playlist?(Y/N)";
                cin >> ch;
                cout << endl;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << " Opening next track..." << endl;
                    ShellExecuteA(NULL, verb, tra[nxt]->url, NULL, NULL, SW_SHOWNORMAL);
                    nxt++;
                }
            }
            else
            {
                cout << " Invalid Option..." << endl;
                goto lt;
            }
            break;

        case 2:
            f = 0, nxt = 0;
            trv = 0;
            count = 0;
            cout << "\tSongs are listed below:" << endl;
            for (trv = 0; trv < 113; trv++)
            {
                if (Tracks[trv].playlist_name1 == "HEART BREAKERS" || Tracks[trv].playlist_name2 == "HEART BREAKERS" || Tracks[trv].playlist_name3 == "HEART BREAKERS")
                {
                    ind[count] = Tracks[trv].index;
                    cout << "\tIndex No." << Tracks[trv].index << endl;
                    cout << "\tName:" << Tracks[trv].name << endl;
                    cout << "\tAlbum:" << Tracks[trv].album_name << endl;
                    cout << "\tGenre:" << Tracks[trv].genre_name << endl;
                    cout << endl;
                    count++;
                }
            }
        hb:
            cout << "Enter the index number of the desired track:";
            cin >> opt2;
            for (i = 0; ind[i] != 0; i++)
            {
                if (ind[i] == opt2)
                {
                    f = 1;
                }
            }
            cout << f;
            if (f == 1)
            {
                find = HeartBreakers.search(opt2, tra);
                cout << " Opening the track in YouTube..." << endl;
                ShellExecuteA(NULL, verb, find->url, NULL, NULL, SW_SHOWNORMAL);
                cout << " Want to play next track in this playlist?(Y/N)";
                cin >> ch;
                cout << endl;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << " Opening next track..." << endl;
                    ShellExecuteA(NULL, verb, tra[nxt]->url, NULL, NULL, SW_SHOWNORMAL);
                    nxt++;
                }
            }
            else
            {
                cout << " Invalid Option..." << endl;
                goto hb;
            }
            break;

        case 3:
            f = 0, nxt = 0;
            trv = 0;
            count = 0;
            cout << "\tSongs are listed below:" << endl;
            for (trv = 0; trv < 113; trv++)
            {
                if (Tracks[trv].playlist_name1 == "ROMANTIC ACOUSTICS" || Tracks[trv].playlist_name2 == "ROMANTIC ACOUSTICS" || Tracks[trv].playlist_name3 == "ROMANTIC ACOUSTICS")
                {
                    ind[count] = Tracks[trv].index;
                    cout << "\tIndex No." << Tracks[trv].index << endl;
                    cout << "\tName:" << Tracks[trv].name << endl;
                    cout << "\tAlbum:" << Tracks[trv].album_name << endl;
                    cout << "\tGenre:" << Tracks[trv].genre_name << endl;
                    cout << endl;
                    count++;
                }
            }
        rm:
            cout << "Enter the index number of the desired track:";
            cin >> opt2;
            for (i = 0; ind[i] != 0; i++)
            {
                if (ind[i] == opt2)
                {
                    f = 1;
                }
            }
            cout << f;
            if (f == 1)
            {
                find = RomanticAcoustics.search(opt2, tra);
                cout << " Opening the track in YouTube..." << endl;
                ShellExecuteA(NULL, verb, find->url, NULL, NULL, SW_SHOWNORMAL);
                cout << " Want to play next track in this playlist?(Y/N)";
                cin >> ch;
                cout << endl;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << " Opening next track..." << endl;
                    ShellExecuteA(NULL, verb, tra[nxt]->url, NULL, NULL, SW_SHOWNORMAL);
                    nxt++;
                }
            }
            else
            {
                cout << " Invalid Option..." << endl;
                goto rm;
            }
            break;

        case 4:
            f = 0, nxt = 0;
            trv = 0;
            count = 0;
            cout << "\tSongs are listed below:" << endl;
            for (trv = 0; trv < 113; trv++)
            {
                if (Tracks[trv].playlist_name1 == "INIYA IRAVU" || Tracks[trv].playlist_name2 == "INIYA IRAVU" || Tracks[trv].playlist_name3 == "INIYA IRAVU")
                {
                    ind[count] = Tracks[trv].index;
                    cout << "\tIndex No." << Tracks[trv].index << endl;
                    cout << "\tName:" << Tracks[trv].name << endl;
                    cout << "\tAlbum:" << Tracks[trv].album_name << endl;
                    cout << "\tGenre:" << Tracks[trv].genre_name << endl;
                    cout << endl;
                    count++;
                }
            }
        ii:
            cout << "Enter the index number of the desired track:";
            cin >> opt2;
            for (i = 0; ind[i] != 0; i++)
            {
                if (ind[i] == opt2)
                {
                    f = 1;
                }
            }
            cout << f;
            if (f == 1)
            {
                find = IniyaIravu.search(opt2, tra);
                cout << " Opening the track in YouTube..." << endl;
                ShellExecuteA(NULL, verb, find->url, NULL, NULL, SW_SHOWNORMAL);
                cout << " Want to play next track in this playlist?(Y/N)";
                cin >> ch;
                cout << endl;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << " Opening next track..." << endl;
                    ShellExecuteA(NULL, verb, tra[nxt]->url, NULL, NULL, SW_SHOWNORMAL);
                    nxt++;
                }
            }
            else
            {
                cout << " Invalid Option..." << endl;
                goto ii;
            }
            break;

        case 5:
            f = 0, nxt = 0;
            trv = 0;
            count = 0;
            cout << "\tSongs are listed below:" << endl;
            for (trv = 0; trv < 113; trv++)
            {
                if (Tracks[trv].playlist_name1 == "PARTY TONIGHT" || Tracks[trv].playlist_name2 == "PARTY TONIGHT" || Tracks[trv].playlist_name3 == "PARTY TONIGHT")
                {
                    ind[count] = Tracks[trv].index;
                    cout << "\tIndex No." << Tracks[trv].index << endl;
                    cout << "\tName:" << Tracks[trv].name << endl;
                    cout << "\tAlbum:" << Tracks[trv].album_name << endl;
                    cout << "\tGenre:" << Tracks[trv].genre_name << endl;
                    cout << endl;
                    count++;
                }
            }
        pto:
            cout << "Enter the index number of the desired track:";
            cin >> opt2;
            for (i = 0; ind[i] != 0; i++)
            {
                if (ind[i] == opt2)
                {
                    f = 1;
                }
            }
            cout << f;
            if (f == 1)
            {
                find = PartyTonight.search(opt2, tra);
                cout << " Opening the track in YouTube..." << endl;
                ShellExecuteA(NULL, verb, find->url, NULL, NULL, SW_SHOWNORMAL);
                cout << " Want to play next track in this playlist?(Y/N)";
                cin >> ch;
                cout << endl;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << " Opening next track..." << endl;
                    ShellExecuteA(NULL, verb, tra[nxt]->url, NULL, NULL, SW_SHOWNORMAL);
                    nxt++;
                }
            }
            else
            {
                cout << " Invalid Option..." << endl;
                goto pto;
            }
            break;
        }
        break;

    case 3:
        cout << "\tSelect your favourite genre from the menu below" << endl;
        cout << "\t1. Party" << endl;
        cout << "\t2. Melody" << endl;
        cout << "\t3. Love" << endl;
        cout << "\t4. Mood" << endl;
        cout << "\t5. Rap" << endl;
        cout << "\t6. Folk" << endl;
        cout << "\tEnter the genre from which you want to choose the track(option):";
        cin >> opt4;
        switch (opt4)
        {
        case 1:
            f = 0, nxt = 0;
            trv = 0;
            count = 0;
            cout << "\tSongs are listed below:" << endl;
            for (trv = 0; trv < 113; trv++)
            {
                if (Tracks[trv].genre_name == "PARTY")
                {
                    ind[count] = Tracks[trv].index;
                    cout << "\tIndex No." << Tracks[trv].index << endl;
                    cout << "\tName:" << Tracks[trv].name << endl;
                    cout << "\tAlbum:" << Tracks[trv].album_name << endl;
                    cout << "\tGenre:" << Tracks[trv].genre_name << endl;
                    cout << endl;
                    count++;
                }
            }
        pt:
            cout << "Enter the index number of the desired track:";
            cin >> opt2;
            for (i = 0; ind[i] != 0; i++)
            {
                if (ind[i] == opt2)
                {
                    f = 1;
                }
            }
            cout << f;
            if (f == 1)
            {
                find = Party.search(opt2, tra);
                cout << " Opening the track in YouTube..." << endl;
                ShellExecuteA(NULL, verb, find->url, NULL, NULL, SW_SHOWNORMAL);
                cout << " Want to play next track in this playlist?(Y/N)";
                cin >> ch;
                cout << endl;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << " Opening next track..." << endl;
                    ShellExecuteA(NULL, verb, tra[nxt]->url, NULL, NULL, SW_SHOWNORMAL);
                    nxt++;
                }
            }
            else
            {
                cout << " Invalid Option..." << endl;
                goto pt;
            }
            break;

        case 2:
            f = 0, nxt = 0;
            trv = 0;
            count = 0;
            cout << "\tSongs are listed below:" << endl;
            for (trv = 0; trv < 113; trv++)
            {
                if (Tracks[trv].genre_name == "MELODY")
                {
                    ind[count] = Tracks[trv].index;
                    cout << "\tIndex No." << Tracks[trv].index << endl;
                    cout << "\tName:" << Tracks[trv].name << endl;
                    cout << "\tAlbum:" << Tracks[trv].album_name << endl;
                    cout << "\tGenre:" << Tracks[trv].genre_name << endl;
                    cout << endl;
                    count++;
                }
            }
        ml:
            cout << "Enter the index number of the desired track:";
            cin >> opt2;
            for (i = 0; ind[i] != 0; i++)
            {
                if (ind[i] == opt2)
                {
                    f = 1;
                }
            }
            cout << f;
            if (f == 1)
            {
                find = Melody.search(opt2, tra);
                cout << " Opening the track in YouTube..." << endl;
                ShellExecuteA(NULL, verb, find->url, NULL, NULL, SW_SHOWNORMAL);
                cout << " Want to play next track in this playlist?(Y/N)";
                cin >> ch;
                cout << endl;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << " Opening next track..." << endl;
                    ShellExecuteA(NULL, verb, tra[nxt]->url, NULL, NULL, SW_SHOWNORMAL);
                    nxt++;
                }
            }
            else
            {
                cout << " Invalid Option..." << endl;
                goto ml;
            }
            break;

        case 3:
            f = 0, nxt = 0;
            trv = 0;
            count = 0;
            cout << "\tSongs are listed below:" << endl;
            for (trv = 0; trv < 113; trv++)
            {
                if (Tracks[trv].genre_name == "LOVE")
                {
                    ind[count] = Tracks[trv].index;
                    cout << "\tIndex No." << Tracks[trv].index << endl;
                    cout << "\tName:" << Tracks[trv].name << endl;
                    cout << "\tAlbum:" << Tracks[trv].album_name << endl;
                    cout << "\tGenre:" << Tracks[trv].genre_name << endl;
                    cout << endl;
                    count++;
                }
            }
        lo:
            cout << "Enter the index number of the desired track:";
            cin >> opt2;
            for (i = 0; ind[i] != 0; i++)
            {
                if (ind[i] == opt2)
                {
                    f = 1;
                }
            }
            cout << f;
            if (f == 1)
            {
                find = Love.search(opt2, tra);
                cout << " Opening the track in YouTube..." << endl;
                ShellExecuteA(NULL, verb, find->url, NULL, NULL, SW_SHOWNORMAL);
                cout << " Want to play next track in this playlist?(Y/N)";
                cin >> ch;
                cout << endl;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << " Opening next track..." << endl;
                    ShellExecuteA(NULL, verb, tra[nxt]->url, NULL, NULL, SW_SHOWNORMAL);
                    nxt++;
                }
            }
            else
            {
                cout << " Invalid Option..." << endl;
                goto lo;
            }
            break;

        case 4:
            f = 0, nxt = 0;
            trv = 0;
            count = 0;
            cout << "\tSongs are listed below:" << endl;
            for (trv = 0; trv < 113; trv++)
            {
                if (Tracks[trv].genre_name == "MOOD")
                {
                    ind[count] = Tracks[trv].index;
                    cout << "\tIndex No." << Tracks[trv].index << endl;
                    cout << "\tName:" << Tracks[trv].name << endl;
                    cout << "\tAlbum:" << Tracks[trv].album_name << endl;
                    cout << "\tGenre:" << Tracks[trv].genre_name << endl;
                    cout << endl;
                    count++;
                }
            }
        mo:
            cout << "Enter the index number of the desired track:";
            cin >> opt2;
            for (i = 0; ind[i] != 0; i++)
            {
                if (ind[i] == opt2)
                {
                    f = 1;
                }
            }
            cout << f;
            if (f == 1)
            {
                find = Mood.search(opt2, tra);
                cout << " Opening the track in YouTube..." << endl;
                ShellExecuteA(NULL, verb, find->url, NULL, NULL, SW_SHOWNORMAL);
                cout << " Want to play next track in this playlist?(Y/N)";
                cin >> ch;
                cout << endl;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << " Opening next track..." << endl;
                    ShellExecuteA(NULL, verb, tra[nxt]->url, NULL, NULL, SW_SHOWNORMAL);
                    nxt++;
                }
            }
            else
            {
                cout << " Invalid Option..." << endl;
                goto mo;
            }
            break;

        case 5:
            f = 0, nxt = 0;
            trv = 0;
            count = 0;
            cout << "\tSongs are listed below:" << endl;
            for (trv = 0; trv < 113; trv++)
            {
                if (Tracks[trv].genre_name == "RAP")
                {
                    ind[count] = Tracks[trv].index;
                    cout << "\tIndex No." << Tracks[trv].index << endl;
                    cout << "\tName:" << Tracks[trv].name << endl;
                    cout << "\tAlbum:" << Tracks[trv].album_name << endl;
                    cout << "\tGenre:" << Tracks[trv].genre_name << endl;
                    cout << endl;
                    count++;
                }
            }
        ra:
            cout << "Enter the index number of the desired track:";
            cin >> opt2;
            for (i = 0; ind[i] != 0; i++)
            {
                if (ind[i] == opt2)
                {
                    f = 1;
                }
            }
            cout << f;
            if (f == 1)
            {
                find = Rap.search(opt2, tra);
                cout << " Opening the track in YouTube..." << endl;
                ShellExecuteA(NULL, verb, find->url, NULL, NULL, SW_SHOWNORMAL);
                cout << " Want to play next track in this playlist?(Y/N)";
                cin >> ch;
                cout << endl;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << " Opening next track..." << endl;
                    ShellExecuteA(NULL, verb, tra[nxt]->url, NULL, NULL, SW_SHOWNORMAL);
                    nxt++;
                }
            }
            else
            {
                cout << " Invalid Option..." << endl;
                goto ra;
            }
            break;

        case 6:
            f = 0, nxt = 0;
            trv = 0;
            count = 0;
            cout << "\tSongs are listed below:" << endl;
            for (trv = 0; trv < 113; trv++)
            {
                if (Tracks[trv].genre_name == "FOLK")
                {
                    ind[count] = Tracks[trv].index;
                    cout << "\tIndex No." << Tracks[trv].index << endl;
                    cout << "\tName:" << Tracks[trv].name << endl;
                    cout << "\tAlbum:" << Tracks[trv].album_name << endl;
                    cout << "\tGenre:" << Tracks[trv].genre_name << endl;
                    cout << endl;
                    count++;
                }
            }
        fo:
            cout << "Enter the index number of the desired track:";
            cin >> opt2;
            for (i = 0; ind[i] != 0; i++)
            {
                if (ind[i] == opt2)
                {
                    f = 1;
                }
            }
            cout << f;
            if (f == 1)
            {
                find = Folk.search(opt2, tra);
                cout << " Opening the track in YouTube..." << endl;
                ShellExecuteA(NULL, verb, find->url, NULL, NULL, SW_SHOWNORMAL);
                cout << " Want to play next track in this playlist?(Y/N)";
                cin >> ch;
                cout << endl;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << " Opening next track..." << endl;
                    ShellExecuteA(NULL, verb, tra[nxt]->url, NULL, NULL, SW_SHOWNORMAL);
                    nxt++;
                }
            }
            else
            {
                cout << " Invalid Option..." << endl;
                goto fo;
            }
            break;
        }

        break;
    }

    cout << "\t\tWe hope u had a good time using this Music Player" << endl;
    cout << "\t\tThank You for using our Music Player we are constantly trying to improve the experience" << endl;
    /*find=LatestTamil.search(109,tra);
    if(find)
    {
        cout<<"Success";
    }
    else
    {
        cout<<"Not found";
    }  
    int i=0;
    while(tra[i]!=0)
    {
        cout<<tra[i]->name<<endl;
        i++;
    }*/
    return 0;
}
