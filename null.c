#define FUSE_USE_VERSION 30

#include <fuse3/fuse.h>
#include <stdio.h>              /* fprintf ().  */
#include <stdlib.h>             /* malloc ().  */

typedef struct {
  struct fuse_fs *next;
} null_t;

static const struct fuse_opt null_opts[] = {
  FUSE_OPT_KEY("-h", 0),
  FUSE_OPT_KEY("--help", 0),
  FUSE_OPT_END
};

static void
null_help (void)
{
  fprintf(stderr, "(no option for the null fusemod)\n");
}

static int
null_opt_proc (void *data, const char *arg, int key,
                struct fuse_args *outargs)
{
  if (key == 0) {
    null_help ();
    return -1;
  }

  return 1;
}

static null_t *
null_get (void)
{
  return fuse_get_context()->private_data;
}

static int
null_getattr (const char *path, struct stat *st)
{
  null_t *null = null_get ();
  return fuse_fs_getattr (null->next, path, st);
}

static int
null_readlink (const char *path, char *buf, size_t capacity)
{
  null_t *null = null_get ();
  return fuse_fs_readlink (null->next, path, buf, capacity);
}

static int
null_mknod (const char *path, mode_t mode, dev_t dev)
{
  null_t *null = null_get ();
  return fuse_fs_mknod (null->next, path, mode, dev);
}

static int
null_mkdir (const char *path, mode_t mode)
{
  null_t *null = null_get ();
  return fuse_fs_mkdir (null->next, path, mode);
}

static int
null_unlink (const char *path)
{
  null_t *null = null_get ();
  return fuse_fs_unlink (null->next, path);
}

static int
null_rmdir (const char *path)
{
  null_t *null = null_get ();
  return fuse_fs_rmdir (null->next, path);
}

static int
null_symlink (const char *contents, const char *path)
{
  null_t *null = null_get ();
  return fuse_fs_symlink (null->next, contents, path);
}

static int
null_rename (const char *oldpath, const char *newpath)
{
  null_t *null = null_get ();
  return fuse_fs_rename (null->next, oldpath, newpath);
}

static int
null_link (const char *oldpath, const char *newpath)
{
  null_t *null = null_get ();
  return fuse_fs_link (null->next, oldpath, newpath);
}

static int
null_chmod (const char *path, mode_t mode)
{
  null_t *null = null_get ();
  return fuse_fs_chmod (null->next, path, mode);
}

static int
null_chown (const char *path, uid_t uid, gid_t gid)
{
  null_t *null = null_get ();
  return fuse_fs_chown (null->next, path, uid, gid);
}

static int
null_truncate (const char *path, off_t off)
{
  null_t *null = null_get ();
  return fuse_fs_truncate (null->next, path, off);
}

static int
null_open (const char *path, struct fuse_file_info *ffi)
{
  null_t *null = null_get ();
  return fuse_fs_open (null->next, path, ffi);
}

static int
null_read (const char *path, char *buf, size_t capacity, off_t off, struct fuse_file_info *ffi)
{
  null_t *null = null_get ();
  return fuse_fs_read (null->next, path, buf, capacity, off, ffi);
}

static int
null_write (const char *path, const char *buf, size_t len, off_t off, struct fuse_file_info *ffi)
{
  null_t *null = null_get ();
  return fuse_fs_write (null->next, path, buf, len, off, ffi);
}

static int
null_statfs (const char *path, struct statvfs *st)
{
  null_t *null = null_get ();
  return fuse_fs_statfs (null->next, path, st);
}

static int
null_flush (const char *path, struct fuse_file_info *ffi)
{
  null_t *null = null_get ();
  return fuse_fs_flush (null->next, path, ffi);
}

static int
null_release (const char *path, struct fuse_file_info *ffi)
{
  null_t *null = null_get ();
  return fuse_fs_release (null->next, path, ffi);
}

static int
null_fsync (const char *path, int datasync, struct fuse_file_info *ffi)
{
  null_t *null = null_get ();
  return fuse_fs_fsync (null->next, path, datasync, ffi);
}

static int
null_setxattr (const char *path, const char *key, const char *value, size_t size, int flags)
{
  null_t *null = null_get ();
  return fuse_fs_setxattr (null->next, path, key, value, size, flags);
}

static int
null_getxattr (const char *path, const char *key, char *buffer, size_t capacity)
{
  null_t *null = null_get ();
  return fuse_fs_getxattr (null->next, path, key, buffer, capacity);
}

static int
null_listxattr (const char *path, char *buffer, size_t capacity)
{
  null_t *null = null_get ();
  return fuse_fs_listxattr (null->next, path, buffer, capacity);
}

static int
null_removexattr (const char *path, const char *key)
{
  null_t *null = null_get ();
  return fuse_fs_removexattr (null->next, path, key);
}

static int
null_opendir (const char *path, struct fuse_file_info *ffi)
{
  null_t *null = null_get ();
  return fuse_fs_opendir (null->next, path, ffi);
}

static int
null_readdir (const char *path, void *buffer, fuse_fill_dir_t filler, off_t off, struct fuse_file_info *ffi)
{
  null_t *null = null_get ();
  return fuse_fs_readdir (null->next, path, buffer, filler, off, ffi);
}

static int
null_releasedir (const char *path, struct fuse_file_info *ffi)
{
  null_t *null = null_get ();
  return fuse_fs_releasedir (null->next, path, ffi);
}

static int
null_fsyncdir (const char *path, int datasync, struct fuse_file_info *ffi)
{
  null_t *null = null_get ();
  return fuse_fs_fsyncdir (null->next, path, datasync, ffi);
}

static void *
null_init (struct fuse_conn_info *fci)
{
  null_t *null = null_get ();
  fuse_fs_init (null->next, fci);
  return null;
}

static void
null_destroy (void *data)
{
  null_t *null = data;
  fuse_fs_destroy (null->next);
}

static int
null_access (const char *path, int how)
{
  null_t *null = null_get ();
  return fuse_fs_access (null->next, path, how);
}

static int
null_create (const char *path, mode_t mode, struct fuse_file_info *ffi)
{
  null_t *null = null_get ();
  return fuse_fs_create (null->next, path, mode, ffi);
}

static int
null_ftruncate (const char *path, off_t off, struct fuse_file_info *ffi)
{
  null_t *null = null_get ();
  return fuse_fs_ftruncate (null->next, path, off, ffi);
}

static int
null_fgetattr (const char *path, struct stat *st, struct fuse_file_info *ffi)
{
  null_t *null = null_get ();
  return fuse_fs_fgetattr (null->next, path, st, ffi);
}

static int
null_lock (const char *path, struct fuse_file_info *ffi, int cmd, struct flock *fl)
{
  null_t *null = null_get ();
  return fuse_fs_lock (null->next, path, ffi, cmd, fl);
}

static int
null_utimens (const char *path, const struct timespec tv[2])
{
  null_t *null = null_get ();
  return fuse_fs_utimens (null->next, path, tv);
}

static int
null_bmap (const char *path, size_t blocksize, uint64_t *idx)
{
  null_t *null = null_get ();
  return fuse_fs_bmap (null->next, path, blocksize, idx);
}

static int
null_ioctl (const char *path, int cmd, void *arg, struct fuse_file_info *ffi, unsigned int flags, void *data)
{
  null_t *null = null_get ();
  return fuse_fs_ioctl (null->next, path, cmd, arg, ffi, flags, data);
}

static int
null_poll (const char *path, struct fuse_file_info *ffi, struct fuse_pollhandle *ph, unsigned *reventsp)
{
  null_t *null = null_get ();
  return fuse_fs_poll (null->next, path, ffi, ph, reventsp);
}

static int
null_write_buf (const char *path, struct fuse_bufvec *buf, off_t off, struct fuse_file_info *ffi)
{
  null_t *null = null_get ();
  return fuse_fs_write_buf (null->next, path, buf, off, ffi);
}

static int
null_read_buf (const char *path, struct fuse_bufvec **bufp, size_t size, off_t off, struct fuse_file_info *ffi)
{
  null_t *null = null_get ();
  return fuse_fs_read_buf (null->next, path, bufp, size, off, ffi);
}

static int
null_flock (const char *path, struct fuse_file_info *ffi, int op)
{
  null_t *null = null_get ();
  return fuse_fs_flock (null->next, path, ffi, op);
}

static int
null_fallocate (const char *path, int mode, off_t off, off_t length, struct fuse_file_info *ffi)
{
  null_t *null = null_get ();
  return fuse_fs_fallocate (null->next, path, mode, off, length, ffi);
}

static const struct fuse_operations null_oper = {
  .getattr = null_getattr,
  .readlink = null_readlink,
  .mknod = null_mknod,
  .mkdir = null_mkdir,
  .unlink = null_unlink,
  .rmdir = null_rmdir,
  .symlink = null_symlink,
  .rename = null_rename,
  .link = null_link,
  .chmod = null_chmod,
  .chown = null_chown,
  .truncate = null_truncate,
  .open = null_open,
  .read = null_read,
  .write = null_write,
  .statfs = null_statfs,
  .flush = null_flush,
  .release = null_release,
  .fsync = null_fsync,
  .setxattr = null_setxattr,
  .getxattr = null_getxattr,
  .listxattr = null_listxattr,
  .removexattr = null_removexattr,
  .opendir = null_opendir,
  .readdir = null_readdir,
  .releasedir = null_releasedir,
  .fsyncdir = null_fsyncdir,
  .init = null_init,
  .destroy = null_destroy,
  .access = null_access,
  .create = null_create,
  .ftruncate = null_ftruncate,
  .fgetattr = null_fgetattr,
  .lock = null_lock,
  .utimens = null_utimens,
  .bmap = null_bmap,
  .ioctl = null_ioctl,
  .poll = null_poll,
  .write_buf = null_write_buf,
  .read_buf = null_read_buf,
  .flock = null_flock,
  .fallocate = null_fallocate,
};

static struct fuse_fs *
null_new (struct fuse_args *args,
           struct fuse_fs *next[])
{
  struct fuse_fs *fs;
  null_t *null = malloc (sizeof *null);
  if (null == NULL)
    {
      fprintf (stderr, "null_new: Cannot allocate memory\n");
      goto fail;
    }

  if (fuse_opt_parse (args, null, null_opts, null_opt_proc))
    {
      fprintf (stderr, "fuse_opt_parse() failed\n");
      goto fail_malloc;
    }

  null->next = next[0];
  fs = fuse_fs_new (&null_oper, sizeof null_oper, null);
  if (fs == NULL)
    {
      fprintf (stderr, "fuse_fs_new() failed\n");
      goto fail_malloc;
    }

  return fs;

 fail_malloc:
  free (null);
 fail:
  return NULL;
}

FUSE_REGISTER_MODULE(null, null_new);
