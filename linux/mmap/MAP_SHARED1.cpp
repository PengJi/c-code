#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main (int argc, char **argv)
{
    int fd;
    int pagesize, offset;
    int len, size;
    char *p_map;
    struct stat sb;

    /* 取得page size */
    pagesize = sysconf (_SC_PAGESIZE);
    printf ("pagesize is %d\n", pagesize);

    /* 打开文件 */
    fd = open (argv[1], O_RDWR, 00777);
    fstat (fd, &sb);

    len = pagesize * 2;
    size = sb.st_size;
    printf("映射内存长度: %d; 文件大小: %d\n", len, size);
    offset = 0;
    //映射两页内存
    p_map = (char *) mmap (NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, offset);
    close (fd);

    printf("开始测试\n");
    printf("访问超过映射大小内存地址\n");
    p_map[len] = '9';      /* 导致段错误 */

    if(size < pagesize) {  //文件大小小于一页大小
        printf("文件大小小于一页大小\n");
        printf("访问文件大小内存地址\n");
        p_map[size] = '9';    /* 正常访问 */
        printf("访问一页大小内存地址\n");
        p_map[pagesize - 1] = '9'; /* 正常访问 */
        printf("访问超过一页大小内存地址\n");
        p_map[pagesize] = '9'; /* 导致总线错误 */
        printf("访问映射大小内存地址\n");
        p_map[len - 1] = '9'; /* 导致总线错误 */
    } else if(size > pagesize) { //文件大小大于一页大小
        printf("文件大小大于一页大小\n");
        printf("访问文件大小内存地址\n");
        p_map[size] = '9';    /* 正常访问 */
        printf("访问一页大小内存地址\n");
        p_map[pagesize - 1] = '9'; /* 正常访问 */
        printf("访问超过一页大小内存地址\n");
        p_map[pagesize] = '9'; /* 正常访问 */
        printf("访问映射大小内存地址\n");
        p_map[len - 1] = '9'; /*  正常访问 */
    } else { //文件大小等于一页大小
        printf("文件大小等于一页大小\n");
        printf("访问文件大小内存地址\n");
        p_map[size] = '9';    /* 导致总线错误 */
        printf("访问一页大小内存地址\n");
        p_map[pagesize - 1] = '9'; /* 正常访问 */
        printf("访问超过一页大小内存地址\n");
        p_map[pagesize] = '9'; /* 导致总线错误 */
        printf("访问映射大小内存地址\n");
        p_map[len - 1] = '9'; /*  导致总线错误 */
    }

    munmap (p_map, len);

    return 0;
}
