int main(int argc, char* argv[])
{

    HANDLE h = CreateFileA(argv[1], (GENERIC_READ | GENERIC_WRITE), (FILE_SHARE_WRITE | FILE_SHARE_READ), 0, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, 0);

    if (h == INVALID_HANDLE_VALUE)
        cout << "Error: " << GetLastError();

    unsigned long bytes = 0;
    FILE_NOTIFY_INFORMATION f[2000];

    if (!ReadDirectoryChangesW(h, &f, 2000, false, FILE_NOTIFY_CHANGE_LAST_WRITE, &bytes, NULL, NULL))
    {
        cout << "Error:" << GetLastError();
    }

    return 0;
  
}
