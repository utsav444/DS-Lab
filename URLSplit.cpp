#include <stdio.h>
#include <string.h>

int main() {
    char url[256], protocol[50] = "", host[100] = "", port[10] = "", path[100] = "/";
    printf("Enter a URL: ");
    scanf("%255s", url);

    char *protocol_pos = strstr(url, "://");
    if (protocol_pos != NULL) {
        strncpy(protocol, url, protocol_pos - url);
        protocol[protocol_pos - url] = '\0';  // Null-terminate the protocol string
        strcpy(url, protocol_pos + 3);
    }

    char *port_pos = strstr(url, ":");
    char *path_pos = strstr(url, "/");
    if (port_pos != NULL) {
        strncpy(host, url, port_pos - url);
        host[port_pos - url] = '\0';  // Null-terminate the host string
        if (path_pos != NULL) {
            strncpy(port, port_pos + 1, path_pos - port_pos - 1);
            port[path_pos - port_pos - 1] = '\0';  // Null-terminate the port string
            strcpy(path, path_pos);  // Copy the path
        } else {
            strcpy(port, port_pos + 1);  // Only the port is present
        }
    } else if (path_pos != NULL) {
        strncpy(host, url, path_pos - url);
        host[path_pos - url] = '\0';  // Null-terminate the host string
        strcpy(path, path_pos);  // Copy the path
    } else {
        strcpy(host, url);  // Only the host is present
    }

    printf("Protocol: %s\n", protocol[0] ? protocol : "None");
    printf("Host/Domain: %s\n", host);
    printf("Port: %s\n", port[0] ? port : "None");
    printf("Path: %s\n", path[0] ? path : "/");

    return 0;
}
