#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<vector<string>> vector_train;
vector<vector<string>> vector_test;
vector<int> f_max;              // tan suat xuat hien tu xuat hien nhieu nhat trong van ban i
map<string, int> df;            // tinh xem tu word nam trong bao nhieu van ban
map<pair<string, int>, int> fe; // tinh xem tu word xuat hien bao nhieu lan trong van ban i <word, i> = int

// tách xâu để đưa vào làm vector phần tử của vector_train và vector_test
vector<string> split_string(string str) {
    vector<string> vt;  // Khởi tạo vector để chứa các chuỗi sau khi tách

    while (!str.empty()) {  // Lặp cho đến khi chuỗi đầu vào không còn phần tử
        string tmp = str.substr(0, str.find(","));  // Tách chuỗi con từ vị trí đầu đến vị trí phần tử ","
        int pos = tmp.find(" ");  // Tìm vị trí đầu tiên của phần tử " " trong chuỗi con

        if (pos > tmp.size()) {
            vt.push_back(tmp);  // Nếu không tìm thấy phần tử " ", thì thêm chuỗi con vào vector
        } else {
            while (pos <= tmp.size()) {  // Nếu tìm thấy phần tử " "
                tmp.erase(pos, 1);  // Xóa phần tử " " khỏi chuỗi con
                pos = tmp.find(" ");  // Tìm lại vị trí phần tử " " tiếp theo
            }
            vt.push_back(tmp);  // Thêm chuỗi con đã xóa các phần tử " " vào vector
        }

        if (str.find(",") > str.size()) {  // Kiểm tra nếu không còn phần tử ","
            break;  // Thoát khỏi vòng lặp
        } else {
            str.erase(0, str.find(",") + 1);  // Xóa phần tử "," và các ký tự trước nó khỏi chuỗi đầu vào
        }
    }

    return vt;  // Trả về vector chứa các chuỗi đã tách
}


// input
void input()
{
    vector<string> document_train;
    vector<string> document_test;

    cin >> n;
    string str_tmp;
    getline(cin, str_tmp);

    for (int i = 0; i < n; i++)
    {
        string str_tmp;
        getline(cin, str_tmp);
        document_train.push_back(str_tmp);
    }

    cin >> q;
    getline(cin, str_tmp);
    for (int i = 0; i < q; i++)
    {
        string str_tmp;
        getline(cin, str_tmp);
        document_test.push_back(str_tmp);
    }

    for (string v : document_train)
    {
        vector<string> element = split_string(v);

        vector_train.push_back(element);
    }

    for (string v : document_test)
    {
        vector<string> element = split_string(v);

        vector_test.push_back(element);
    }
}

// preprocessing
void pre_processing() {
    // Tính tần suất từ xuất hiện nhiều nhất trong văn bản i
    for (vector<string> str_tmp : vector_train) {
        map<string, int> m;  // Khởi tạo một map để đếm tần suất xuất hiện của các từ

        int max_f = 0;  // Biến để lưu tần suất từ xuất hiện nhiều nhất trong văn bản i
        for (string word_tmp : str_tmp) {
            // Tìm từ trong map
            map<string, int>::iterator ite = m.find(word_tmp);
            if (ite == m.end()) {  // Nếu từ chưa có trong map
                m.insert({word_tmp, 1});  // Thêm từ vào map với tần suất xuất hiện ban đầu là 1
            } else {  // Nếu từ đã có trong map
                ite->second += 1;  // Tăng tần suất xuất hiện của từ lên 1
            }
            max_f = max(m[word_tmp], max_f);  // Cập nhật tần suất từ xuất hiện nhiều nhất
        }
        f_max.push_back(max_f);  // Thêm tần suất từ xuất hiện nhiều nhất vào vector f_max
    }
}


// tinh xem word xuat hien bao nhieu lan trong van ban i
int frequence_word_int_document_i(string word, int i)
{
    if(fe.find({word, i}) != fe.end()){ // neu da co trong kho luu tru thi lay ra va tra ve
        return fe[{word, i}];
    }

    int index = 0;
    vector<string> str_tmp = vector_train[i];

    for(string v : str_tmp){
        if(word == v) index++;
    }

    fe.insert({{word, i}, index});
    return index;

}

int count_document_contain_word(string word){ // neu da co trong kho luu tru thi lay ket qua va tra ve
    if(df.find(word) != df.end()){
        return df[word];
    }

    int index = 0;
    for(vector<string> str_tmp : vector_train){

        vector<string>::iterator ite = find(str_tmp.begin(), str_tmp.end(), word);
        if(ite != str_tmp.end()){
            index++;
        }
    }

    df.insert({word,index});
    return index;
}

// du doan van ban
int search_engine(vector<string> list_word)
{
    double score_max = -1000;
    int predict_label = -1;
    for(int i=0; i<n; i++){
        vector<string> list_word_train_doc = vector_train[i];

        double score = 0;
        for(string word : list_word){
            if(find(list_word_train_doc.begin(), list_word_train_doc.end(), word) == list_word_train_doc.end()){ // tu nay khong xuat hien trong van ban
                continue;
            } else {
                int ftd = frequence_word_int_document_i(word, i);
                int dft = count_document_contain_word(word);
                int maxfd = f_max[i];

                double tf_word = 0.5 + 0.5 * ((double) ftd / maxfd);
                double idf_word = log2((double) n / dft);

                score += tf_word * idf_word;
            }
        }

        if(score > score_max) {
            predict_label = i;
            score_max = score;
        }
    }

    return predict_label + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    pre_processing();

    for (int i = 0; i < q; i++)
        cout << search_engine(vector_test[i]) << endl;

    return 0;
}