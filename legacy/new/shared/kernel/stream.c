#include <kernel/memory.h>
#include <kernel/stream.h>

umax stream_count_created = 0;
umax stream_count_opened = 0;

stream_t *stream_open()
{
    stream_t *stream = memory_allocate_unaligned(sizeof(stream_t));
    if (stream == NULL) return NULL;
    *(umax *) &stream->desc = stream_count_created++;
    ++stream_count_opened;
    return stream;
}

r8 stream_close(stream_t *stream)
{
    if (stream == NULL || stream->desc >= stream_count_created) return 1;
    if (memory_free(stream)) return 2;
    --stream_count_opened;
    return 0;
}

umax stream_count()
{
    return stream_count_opened;
}
