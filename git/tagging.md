# Viewing and Searchin Tags

To see all the tags, run: `git tag` 

To search for a tag, run: `git tag -l "search-string"`
For example: `git tag -l "v1.0.0"`

# Creating Tags

Git supports 2 types of tags:

1) Lightweight: Kinda like a branch that doesn’t change — it’s just
                a pointer to a specific commit.

2) Annotated:   These are stored as full objects in the Git database. They’re checksummed;
                contain the tagger name, email, and date; have a tagging message; and can be signed and verified
                with GNU Privacy Guard (GPG).

*N.B.: It's generally recommended that you use annotated tags.*

## Annotated Tags

We can create an annotate tag using the command: `git tag -a v0.5.0 -m "First public beta"` 
Here, the `-m` flag is used to provide the tagging message. If not provided, Git will open your editor just like
in the case of commit messages.

You can see the tag data associated with a tag by using the following tag: `git show v0.5.0`

## Lightweight Tags

To create lightweight tags, use the command: `git tag v0.5.0`. Notice that we don't use any flags here. This the 
difference in the command.

# Tagging Commits After Moving Past Them

Let's say that we forgot to tag a commit and we've now moved past that commit by making new commits on top of that commit.
To tag that commit, first we'll need to use `git log` to find the commit hash. Then, we need to run the following command:
`git tag -a v1.2.0 <commit-hash>`.

The above command will set a tag at that commit and ask you to provide a commit message.

# Pushing Tags To Remote

By default, Git won't push the tags to remote. You'll need to push them to remote just like you need to push local branches.
To push a tag to remote, run: `git push <remote_name> <tag_name>`.
For exmaple: `git push origin v0.2.0`

If you have a lot of tags, and would like to push them all to a remote, then use the `--tags` flag.
For exmaple: `git push origin --tags`

# Deleting Tags

To delete a tag, run: `git tag -d <tag_name>`. For exmaple: `git tag -d v0.1.0`.

This will only delete the tag locally. It won't push it to any remote. To push it to remote,
run: `git push origin --delete <tag_name>`. For exmaple: `git push origin --delete v0.1.0`.

# Checking Out Tags

If you want to view the source code of the a specific tagged version of your project, then you can checkout to that version of
the source code using something like `git checkout v0.5.0`.

However, you'll be in *detached HEAD* state. Any commits you make in this state will create commits that are unreachable unless the
commit hash is used directly.

To properly make changes from those tagged versions (for bug fixes for exmaple), then you'll need to brach off from there by running
a similar command like this: `git checkout -b <branch_name> v0.5.0`.
