# How commits work under the hood

Each commit in Git has some `metadata` associated with it, points to a `tree`
and also points to one or more `blobs`. (The `tree` lists the contents of the
directory and specifies which file names are stored as which blobs. On the other
hand, each `blob` represent the contents of a file.)

Each commit in Git (except the initial commit) has a pointer that points to the
previous commit.

A branch in Git is simply a lightweight movable pointer to one of these commits.

Git uses a special pointer called `HEAD` to keep track of which branch you're
currently on.

`git log --decorate` will show where the branch pointers are pointing.

Please note, `git log` by default will only show the commit history of the the
current branch you're on. If you want to see the commit history of all the
branches, then run: `git log --all`.

To only create a branch, run: `git branch <branch_name>`

To create a branch and switch to it at the same time, run:
`git checkout -b <branch_name>`

From Git 2.23 onwards:

- Switching branches: `git switch <branch_name>`
- Creating and switching branches: `git switch -c <branch_name>`
- Return to your previously checked out branch: `git switch -`

Please note that, before switching to a new branch, we have to make sure that
there is no uncommited changes in our working directory or staging area.
Otherwise, Git won't let us switch to a different branch. (You may use
`git stash` to alleviate that problem)

# Basic Branching and Merging

Let's say we have a branch _bug_fix_ and we want to merge it with the master
branch, we first switch to the master branch (`git switch master`) and then run:
`git merge bug_fix`.

If there is no divergent path, git does a _fast-forward_ merge. Otherwise, it
raises a merge conflict.

The `merge` command performs a three-way merge between the two latest branch
snapshots of each branch and the most recent common ancestor of the two
branches.

After merging a branch, usually we delete it. To delete a branch, we run:
`git branch -d <branch_name>`.

If we have changes in the same section of the same file in the two branches we
were trying to merge, then we will get a merge conflict. In case of a merge
conflict, we can run `git status` to see the files that are causing the
conflict. We then can resolve the conflict and run `git add` to add those files
to the staging area and then run `git commit` to commit those changes.

(Merge conflicts are usually marked with the >>, << and == markers)

If you want to use a graphical tool to fix the merge conflict, you can run:
`git mergetool`.

`git branch` without any arguments will list all the branches. To view all the
branches you've merged into the branch you're currently on, run:
`git branch --merged`. To do the opposite, run: `git branch --no-merged`.

Please note, branches that have been successfully merged can be deleted with
`git branch -d <branch_name>`. If you try to delete a branch you've not merged
yet, Git won't allow you to do so like so. To delete such a branch and lose work
done in that branch, run: `git branch -D <branch_name>`.

The name of a branch can be changed by running:
`git branch --move <old_branch_name> <new_branch_name>`.

The above command will only change the name locally. To upstream it, run:
`git push --set-upstream <remote_name> <new_branch_name>`.

After doing so, the only thing left to do delete the redundant <old_branch_name>
in remote. To do so, run: `git push <remote_name> --delete <old_branch_name>`.

# Remote Branches

Remote references are references (pointers) in your remote repos (branches, tags
etc). To get a full list of remote references, run: `git ls-remote <remote>` or
`git remote show <remote>`.

Remote-tracking branches are references to the state of remote branches. They’re
local references that you can’t move; Git moves them for you whenever you do any
network communication, to make sure they accurately represent the state of the
remote repository. Remote-tracking branch names take the form
`<remote>/<branch>`. For example: `origin/master` branch.

When you use `git clone` to pull down a repo, git automatically names it
`origin` for you, pulls down all the data, creates a pointer to where its
`master` branch is, and name it `origin/master` locally. Git also gives you your
own local master branch starting at the same place as origin’s master branch, so
you have something to work from.

_Please note that, just like the branch name “master” does not have any special
meaning in Git, neither does “origin”. While “master” is the default name for a
starting branch when you run git init which is the only reason it’s widely used,
“origin” is the default name for a remote when you run git clone. If you run
`git clone -o booyah` instead, then you will have `booyah/master` as your
default remote branch._

To synchronize your work with a given remote, you run: `git fetch <remote>`.
(For example: `git fetch origin`).

After fetching the changes from remote using `git fetch`, you'll have to run
`git merge` to merge the changes with your local branch.

### Q: What's the difference between `pull` and `fetch`?

Ans: The most significant difference between `git pull` and `git fetch` is that
`git pull` automatically merges the fetched changes into the current branch,
while `git fetch` does not. This makes `git pull` a more convenient command if
you want to quickly update your local branch with changes from the remote
repository.

To push a branch to a specific remote, run: `git push <remote> <branch>`. For
example: `git push origin master`.

To push a local branch to a remote branch with a different name, run:
`git push <remote> <local_name>:<remote_name>`.

(For example: `git push origin fix_my_mistake:fix_bug77` will push the
`fix_my_mistake` local branch to the remote branch `fix_bug77`)

To create a local branch based off of a remote branch, run:
`git checkout -b <local_name> <remote>/<remote_branch_name>`.

For example: `git checkout -b hotfix123 origin/issue123` will create a new local
branch `hotfix123` based off of the remote branch `issue123`.

Checking out a local branch from a remote-tracking branch automatically creates
what is called a _tracking branch_ (and the branch it tracks is called an
_upstream branch_). Tracking branches are local branches that have a direct
relationship to a remote branch. If you’re on a tracking branch and type
`git pull`, Git automatically knows which server to fetch from and which branch
to merge in. It's such a common operation that git provides a shortcut for it:
`git checkout --track <remote>/<remote_branch_name>`. In fact, this is so common
that there’s even a shortcut for that shortcut. If the branch name you’re trying
to checkout (a) doesn’t exist and (b) exactly matches a name on only one remote,
Git will create a tracking branch for you.

If you already have a local branch and want to set it to a remote branch or want
to change the upstream branch you're tracking, you can use the `-u` or
`--set-upstream-to` flag. For example: `git branch -u origin/new_issue77` will
make that branch you're currently on track the remote branch `new_issue77`.

If you want to see what tracking branches you've set up and their state, run:
`git branch -vv`. This will show you the remote branches that are being tracked
by local branches and whether they're ahead or behind.

Please note that, the info shown by the above command can be stale. To get the
latest info, run `git fetch --all` and try again by running `git branch -vv`.

While the `git fetch` command will fetch all the changes on the server that you
don’t have yet, it will not modify your working directory at all. It will simply
get the data for you and let you merge it yourself. However, there is a command
called `git pull` which is essentially a `git fetch` immediately followed by a
`git merge` in most cases. If you have a tracking branch set up as demonstrated
in the last section, either by _explicitly setting it_ or by _having it created
for you by the clone or checkout commands_, `git pull` will look up what server
and branch your current branch is tracking, fetch from that server and then try
to merge in that remote branch. **Generally it’s better to simply use the fetch
and merge commands explicitly as the magic of git pull can often be confusing.**

To delete a remote branch, run:
`git push <remote> --delete <remote_branch_name>`.

For example: `git push origin --delete new_issue77`.

_Basically all this does is to remove the pointer from the server. The Git
server will generally keep the data there for a while until a garbage collection
runs, so if it was accidentally deleted, it’s often easy to recover._

# Git Rebase

In git, there is 2 main ways to intergrate changes from one branch into another:
`merge` and `rebase`.

When we `merge` two branches, it creates a three-way merge. This may complicate
the history. For large scale projects, it's good to have a linear history rather
than a branching one. (See `Pro Git` page 96 figure)

A linear history can be achieved by using `git rebase`.

`git rebase` takes the commits introduced in the current branch and replays them
over the specified branch.

For example, to replay the commits introduced in the `issue123` branch to the `master`
branch and do a _fast-forward_ merge (See `Pro Git` page 96 and 97 figures), you'll
need to run the following commands:

```sh
git switch issue123
git rebase master

git switch master
git merge issue123
```

Please note, `git rebase <branch_name>` not only replays the commits introduced
in the current branch on top of the `<branch_name>` branch, but also moves the
branch pointer to the last replayed commit. But, the `<branch_name>` branch
still has its pointer unmoved. That's why we do a `git merge` to move the
`<branch_name>`'s pointer to the correct position. (See `Pro Git` page 96 and 97
for figures)

## More interesting rebases

Let's say you have a branch that has branched off the `master` branch named `server`. Let's
say there's another branch named `client` that later on got branched off of `server`.

Now, you want to commit the patches introduced in the `client` branch to the `master` branch.
You can use the following command to achieve that:
`git rebase --onto master server client`
