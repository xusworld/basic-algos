
固定映射区（Fixing Mapping Region）：该区域和4G的顶端只有4k的隔离带，其每个地址项都服务于特定的用途，如ACPI_BASE等。

永久内存映射区（PKMap Region）：该区域可访问高端内存。访问方法是使用alloc_page(_GFP_HIGHMEM)分配高端内存页或者使用kmap函数将分配到的高端内存映射到该区域。

动态内存映射区（Vmalloc Region）：该区域由内核函数vmalloc来分配，特点是：线性空间连续，但是对应的物理空间不一定连续。vmalloc分配的线性地址所对应的物理页可能处于低端内存，也可能处于高端内存。

直接映射区（Direct Memory Region）：线性空间中从3G开始最大896M的区间，为直接内存映射区，该区域的线性地址和物理地址存在线性转换关系：线性地址=3G+物理地址。
