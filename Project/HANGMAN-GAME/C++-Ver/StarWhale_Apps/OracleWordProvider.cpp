/* (same header block, Filename: OracleWordProvider.cpp) */

#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <occi.h>
#include "OracleWordProvider.h"

using namespace oracle::occi;

bool OracleWordProvider::readConfig(const char* path, std::string& user,
    std::string& password, std::string& connect) {
    std::ifstream file(path);
    if (!file) return false;

    std::string line;
    while (std::getline(file, line)) {
        size_t eq = line.find('=');
        if (eq == std::string::npos) continue;
        std::string key = line.substr(0, eq);
        std::string value = line.substr(eq + 1);
        if (key == "user") user = value;
        else if (key == "password") password = value;
        else if (key == "connect") connect = value;
    }
    return !user.empty() && !password.empty() && !connect.empty();
}

bool OracleWordProvider::load(const char* source) {
    std::string user, password, connect;
    if (!readConfig(source, user, password, connect)) return false;

    Environment* env = nullptr;
    Connection* conn = nullptr;
    m_entries.clear();

    try {
        env = Environment::createEnvironment(Environment::DEFAULT);
        conn = env->createConnection(user, password, connect);

        Statement* stmt = conn->createStatement(
            "SELECT word, hint FROM hangman_words ORDER BY word_id");
        ResultSet* rs = stmt->executeQuery();

        while (rs->next()) {
            m_entries.push_back({ rs->getString(1), rs->getString(2) });
        }

        stmt->closeResultSet(rs);
        conn->terminateStatement(stmt);
        env->terminateConnection(conn);
        Environment::terminateEnvironment(env);
    }
    catch (SQLException&) {
        if (conn) env->terminateConnection(conn);
        if (env) Environment::terminateEnvironment(env);
        m_entries.clear();
        return false;   // Caller falls back to file
    }

    std::srand(static_cast<unsigned>(std::time(nullptr)));
    return !m_entries.empty();
}

const char* OracleWordProvider::getRandomWord() {
    if (m_entries.empty()) return nullptr;
    return m_entries[std::rand() % m_entries.size()].word.c_str();
}

const char* OracleWordProvider::getHintForWord(const char* word) const {
    if (!word) return nullptr;
    for (const auto& e : m_entries) {
        if (e.word == word) return e.hint.c_str();
    }
    return nullptr;
}

int OracleWordProvider::wordCount() const {
    return static_cast<int>(m_entries.size());
}